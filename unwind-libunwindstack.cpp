#include <string>

#include <unwindstack/Regs.h>
#include <unwindstack/Unwinder.h>
#include <unwindstack/Error.h>
#include <cxxabi.h>
extern "C" {
#include "unwind.h"
#include "error_prints.h"
static void init();
static void* tcb_init(struct tcb* tcp);
static void tcb_fin(struct tcb* tcp);
static void tcb_walk(struct tcb* tcp, unwind_call_action_fn call_action, unwind_error_action_fn error_action, void* data);
}

constexpr size_t kMaxFrames =  512;

namespace {

std::string demangleNameIfNeeded(const std::string& name) {
  if (name.length() < 2 || name[0] != '_') {
    return name;
  }

  char* demangled_str = nullptr;
  if (name[1] == 'Z') {
    // Try to demangle C++ name.
    demangled_str = abi::__cxa_demangle(name.c_str(), nullptr, nullptr, nullptr);
  }

  if (demangled_str == nullptr) {
    return name;
  }

  std::string demangled_name(demangled_str);
  free(demangled_str);
  return demangled_name;
}
}

void init() {
}

void* tcb_init(struct tcb* tcp) {
  return new std::unique_ptr<unwindstack::UnwinderFromPid>(new unwindstack::UnwinderFromPid(kMaxFrames, tcp->pid));
}

void tcb_fin(struct tcb* tcp) {
  auto* unwinder = reinterpret_cast<std::unique_ptr<unwindstack::UnwinderFromPid>*>(tcp->unwind_ctx);
  delete unwinder;
}

void tcb_walk(struct tcb* tcp, unwind_call_action_fn call_action, unwind_error_action_fn error_action, void* data) {
  auto& unwinder = *reinterpret_cast<std::unique_ptr<unwindstack::UnwinderFromPid>*>(tcp->unwind_ctx);
    unwindstack::ErrorData error = {
      .code = unwindstack::ERROR_NONE,
      .address = 0,
    };

    std::unique_ptr<unwindstack::Regs> regs(unwindstack::Regs::RemoteGet(tcp->pid));
    if (regs == nullptr) {
      error_func_msg_and_die("Failed to fetch the registers.");
    }

    constexpr int kMaxRetry = 2;
    for (int i = 0; i < kMaxRetry; i++) {
      unwinder->SetArch(regs->Arch());
      if (!unwinder->Init()) {
        error_func_msg_and_die("Failed to initialize the unwinder: %s.", unwinder->LastErrorCodeString());
      }
      unwinder->SetRegs(regs.get());
      unwinder->Unwind(nullptr, nullptr);
      std::vector<unwindstack::FrameData> frames = unwinder->ConsumeFrames();
      error.code = unwinder->LastErrorCode();
      if (error.code == unwindstack::ERROR_MEMORY_INVALID) {
        error.address = unwinder->LastErrorAddress();
      }
      unwinder->SetRegs(nullptr);
      if (error.code != unwindstack::ERROR_NONE) {
        unwinder.reset(new unwindstack::UnwinderFromPid(kMaxFrames, tcp->pid));
        continue;
      }
      for (const auto& frame: frames) {
        std::string functionName = demangleNameIfNeeded(frame.function_name);
        call_action(data, frame.map_name.c_str(), functionName.c_str(), static_cast<unwind_function_offset_t>(frame.function_offset), static_cast<unsigned long>(frame.map_exact_offset));
      }
      break;
    }
    // TODO: calculate the true offset for ERROR_MEMORY_INVALID.
    if (error.code != unwindstack::ERROR_NONE) {
      error_action(data, unwindstack::GetErrorCodeString(error.code), 0);
    }
}


const struct unwind_unwinder_t unwinder = {
  .name = "libunwindstack",
  .init = init,
  .tcb_init = tcb_init,
  .tcb_fin = tcb_fin,
  .tcb_walk = tcb_walk,
};
