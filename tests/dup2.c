#include "tests.h"
#include <sys/syscall.h>

#ifdef __NR_dup2

# include <errno.h>
# include <stdio.h>
# include <unistd.h>

int
main(void)
{
	const long int fd_old = (long int) 0xdeadbeefffffffff;
	const long int fd_new = (long int) 0xdeadbeeffffffffe;
	int rc = syscall(__NR_dup2, fd_old, fd_new);
	printf("dup2(%d, %d) = %d %s (%m)\n",
	       (int) fd_old, (int) fd_new, rc,
	       errno == ENOSYS ? "ENOSYS" : "EBADF");

	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_dup2")

#endif
