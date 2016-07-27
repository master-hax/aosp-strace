#include "tests.h"
#include <sys/syscall.h>

#ifdef __NR_vhangup

# include <stdio.h>
# include <unistd.h>

int
main(void)
{
	if (setsid() == -1)
		perror_msg_and_skip("setsid");

	long rc = syscall(__NR_vhangup);

	/*
	 * On setsid() success, the new session has no controlling terminal,
	 * therefore a subsequent vhangup() has nothing to hangup.
	 *
	 * The system call, however, returns 0 iff the calling process
	 * has CAP_SYS_TTY_CONFIG capability.
	 */
	if (rc)
		printf("vhangup() = %ld %s (%m)\n", rc, errno2name());
	else
		puts("vhangup() = 0");

	puts("+++ exited with 0 +++");
	return 0;
}

#else

SKIP_MAIN_UNDEFINED("__NR_vhangup")

#endif
