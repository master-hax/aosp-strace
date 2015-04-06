<<<<<<< HEAD   (c9ad03 Merge "Fix strace mips64 build.")
=======
CFLAGS += -Wall

PROGS = \
    vfork fork sig skodic clone leaderkill childthread \
    sigkill_rain wait_must_be_interruptible threaded_execve \
    mtd ubi seccomp sfd mmap_offset_decode x32_lseek x32_mmap \
    many_looping_threads

all: $(PROGS)

leaderkill: LDFLAGS += -pthread

childthread: LDFLAGS += -pthread

many_looping_threads: LDFLAGS += -pthread

clean distclean:
	rm -f *.o core $(PROGS) *.gdb

.PHONY: all clean distclean
>>>>>>> BRANCH (87af19 Cleanup process_vm_writev syscall decoding)
