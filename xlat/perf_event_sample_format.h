/* Generated by ./xlat/gen.sh from ./xlat/perf_event_sample_format.in; do not edit. */

#include "gcc_compat.h"
#include "static_assert.h"

#if defined(PERF_SAMPLE_IP) || (defined(HAVE_DECL_PERF_SAMPLE_IP) && HAVE_DECL_PERF_SAMPLE_IP)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_IP) == (1 << 0), "PERF_SAMPLE_IP != 1 << 0");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_IP 1 << 0
#endif
#if defined(PERF_SAMPLE_TID) || (defined(HAVE_DECL_PERF_SAMPLE_TID) && HAVE_DECL_PERF_SAMPLE_TID)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_TID) == (1 << 1), "PERF_SAMPLE_TID != 1 << 1");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_TID 1 << 1
#endif
#if defined(PERF_SAMPLE_TIME) || (defined(HAVE_DECL_PERF_SAMPLE_TIME) && HAVE_DECL_PERF_SAMPLE_TIME)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_TIME) == (1 << 2), "PERF_SAMPLE_TIME != 1 << 2");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_TIME 1 << 2
#endif
#if defined(PERF_SAMPLE_ADDR) || (defined(HAVE_DECL_PERF_SAMPLE_ADDR) && HAVE_DECL_PERF_SAMPLE_ADDR)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_ADDR) == (1 << 3), "PERF_SAMPLE_ADDR != 1 << 3");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_ADDR 1 << 3
#endif
#if defined(PERF_SAMPLE_READ) || (defined(HAVE_DECL_PERF_SAMPLE_READ) && HAVE_DECL_PERF_SAMPLE_READ)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_READ) == (1 << 4), "PERF_SAMPLE_READ != 1 << 4");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_READ 1 << 4
#endif
#if defined(PERF_SAMPLE_CALLCHAIN) || (defined(HAVE_DECL_PERF_SAMPLE_CALLCHAIN) && HAVE_DECL_PERF_SAMPLE_CALLCHAIN)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_CALLCHAIN) == (1 << 5), "PERF_SAMPLE_CALLCHAIN != 1 << 5");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_CALLCHAIN 1 << 5
#endif
#if defined(PERF_SAMPLE_ID) || (defined(HAVE_DECL_PERF_SAMPLE_ID) && HAVE_DECL_PERF_SAMPLE_ID)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_ID) == (1 << 6), "PERF_SAMPLE_ID != 1 << 6");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_ID 1 << 6
#endif
#if defined(PERF_SAMPLE_CPU) || (defined(HAVE_DECL_PERF_SAMPLE_CPU) && HAVE_DECL_PERF_SAMPLE_CPU)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_CPU) == (1 << 7), "PERF_SAMPLE_CPU != 1 << 7");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_CPU 1 << 7
#endif
#if defined(PERF_SAMPLE_PERIOD) || (defined(HAVE_DECL_PERF_SAMPLE_PERIOD) && HAVE_DECL_PERF_SAMPLE_PERIOD)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_PERIOD) == (1 << 8), "PERF_SAMPLE_PERIOD != 1 << 8");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_PERIOD 1 << 8
#endif
#if defined(PERF_SAMPLE_STREAM_ID) || (defined(HAVE_DECL_PERF_SAMPLE_STREAM_ID) && HAVE_DECL_PERF_SAMPLE_STREAM_ID)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_STREAM_ID) == (1 << 9), "PERF_SAMPLE_STREAM_ID != 1 << 9");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_STREAM_ID 1 << 9
#endif
#if defined(PERF_SAMPLE_RAW) || (defined(HAVE_DECL_PERF_SAMPLE_RAW) && HAVE_DECL_PERF_SAMPLE_RAW)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_RAW) == (1 << 10), "PERF_SAMPLE_RAW != 1 << 10");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_RAW 1 << 10
#endif
#if defined(PERF_SAMPLE_BRANCH_STACK) || (defined(HAVE_DECL_PERF_SAMPLE_BRANCH_STACK) && HAVE_DECL_PERF_SAMPLE_BRANCH_STACK)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_BRANCH_STACK) == (1 << 11), "PERF_SAMPLE_BRANCH_STACK != 1 << 11");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_BRANCH_STACK 1 << 11
#endif
#if defined(PERF_SAMPLE_REGS_USER) || (defined(HAVE_DECL_PERF_SAMPLE_REGS_USER) && HAVE_DECL_PERF_SAMPLE_REGS_USER)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_REGS_USER) == (1 << 12), "PERF_SAMPLE_REGS_USER != 1 << 12");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_REGS_USER 1 << 12
#endif
#if defined(PERF_SAMPLE_STACK_USER) || (defined(HAVE_DECL_PERF_SAMPLE_STACK_USER) && HAVE_DECL_PERF_SAMPLE_STACK_USER)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_STACK_USER) == (1 << 13), "PERF_SAMPLE_STACK_USER != 1 << 13");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_STACK_USER 1 << 13
#endif
#if defined(PERF_SAMPLE_WEIGHT) || (defined(HAVE_DECL_PERF_SAMPLE_WEIGHT) && HAVE_DECL_PERF_SAMPLE_WEIGHT)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_WEIGHT) == (1 << 14), "PERF_SAMPLE_WEIGHT != 1 << 14");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_WEIGHT 1 << 14
#endif
#if defined(PERF_SAMPLE_DATA_SRC) || (defined(HAVE_DECL_PERF_SAMPLE_DATA_SRC) && HAVE_DECL_PERF_SAMPLE_DATA_SRC)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_DATA_SRC) == (1 << 15), "PERF_SAMPLE_DATA_SRC != 1 << 15");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_DATA_SRC 1 << 15
#endif
#if defined(PERF_SAMPLE_IDENTIFIER) || (defined(HAVE_DECL_PERF_SAMPLE_IDENTIFIER) && HAVE_DECL_PERF_SAMPLE_IDENTIFIER)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_IDENTIFIER) == (1 << 16), "PERF_SAMPLE_IDENTIFIER != 1 << 16");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_IDENTIFIER 1 << 16
#endif
#if defined(PERF_SAMPLE_TRANSACTION) || (defined(HAVE_DECL_PERF_SAMPLE_TRANSACTION) && HAVE_DECL_PERF_SAMPLE_TRANSACTION)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_TRANSACTION) == (1 << 17), "PERF_SAMPLE_TRANSACTION != 1 << 17");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_TRANSACTION 1 << 17
#endif
#if defined(PERF_SAMPLE_REGS_INTR) || (defined(HAVE_DECL_PERF_SAMPLE_REGS_INTR) && HAVE_DECL_PERF_SAMPLE_REGS_INTR)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_REGS_INTR) == (1 << 18), "PERF_SAMPLE_REGS_INTR != 1 << 18");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_REGS_INTR 1 << 18
#endif
#if defined(PERF_SAMPLE_PHYS_ADDR) || (defined(HAVE_DECL_PERF_SAMPLE_PHYS_ADDR) && HAVE_DECL_PERF_SAMPLE_PHYS_ADDR)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((PERF_SAMPLE_PHYS_ADDR) == (1 << 19), "PERF_SAMPLE_PHYS_ADDR != 1 << 19");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define PERF_SAMPLE_PHYS_ADDR 1 << 19
#endif

#ifndef XLAT_MACROS_ONLY

# ifdef IN_MPERS

#  error static const struct xlat perf_event_sample_format in mpers mode

# else

static
const struct xlat perf_event_sample_format[] = {
 XLAT(PERF_SAMPLE_IP),
 XLAT(PERF_SAMPLE_TID),
 XLAT(PERF_SAMPLE_TIME),
 XLAT(PERF_SAMPLE_ADDR),
 XLAT(PERF_SAMPLE_READ),
 XLAT(PERF_SAMPLE_CALLCHAIN),
 XLAT(PERF_SAMPLE_ID),
 XLAT(PERF_SAMPLE_CPU),
 XLAT(PERF_SAMPLE_PERIOD),
 XLAT(PERF_SAMPLE_STREAM_ID),
 XLAT(PERF_SAMPLE_RAW),
 XLAT(PERF_SAMPLE_BRANCH_STACK),
 XLAT(PERF_SAMPLE_REGS_USER),
 XLAT(PERF_SAMPLE_STACK_USER),
 XLAT(PERF_SAMPLE_WEIGHT),
 XLAT(PERF_SAMPLE_DATA_SRC),
 XLAT(PERF_SAMPLE_IDENTIFIER),
 XLAT(PERF_SAMPLE_TRANSACTION),
 XLAT(PERF_SAMPLE_REGS_INTR),
 XLAT(PERF_SAMPLE_PHYS_ADDR),
 XLAT_END
};

# endif /* !IN_MPERS */

#endif /* !XLAT_MACROS_ONLY */