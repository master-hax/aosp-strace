<<<<<<< HEAD   (6967bc Merge "support building w/out system shm/sem/ipc/msg headers)
/*
 * Copyright (c) 1993 Ulrich Pegelow <pegelow@moorea.uni-muenster.de>
 * Copyright (c) 1993 Branko Lankester <branko@hacktic.nl>
 * Copyright (c) 1993, 1994, 1995, 1996 Rick Sladkey <jrs@world.std.com>
 * Copyright (c) 1996-1999 Wichert Akkerman <wichert@cistron.nl>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "defs.h"
#ifdef HAVE_MQUEUE_H
# include <mqueue.h>
#endif
#include <fcntl.h>
#ifdef HAVE_SYS_IPC_H
# include <sys/ipc.h>
#endif
#ifdef HAVE_SYS_SEM_H
# include <sys/sem.h>
#endif
#ifdef HAVE_SYS_MSG_H
# include <sys/msg.h>
#endif
#ifdef HAVE_SYS_SHM_H
# include <sys/shm.h>
#endif
#ifdef HAVE_LINUX_MQUEUE_H
# include <linux/mqueue.h>
#endif
#ifdef HAVE_LINUX_SEM_H
# include <linux/sem.h>
#endif

#ifndef MSG_STAT
#define MSG_STAT 11
#endif
#ifndef MSG_INFO
#define MSG_INFO 12
#endif
#ifndef SHM_STAT
#define SHM_STAT 13
#endif
#ifndef SHM_INFO
#define SHM_INFO 14
#endif
#ifndef SEM_STAT
#define SEM_STAT 18
#endif
#ifndef SEM_INFO
#define SEM_INFO 19
#endif

#if !defined IPC_64
# define IPC_64 0x100
#endif

extern void printsigevent(struct tcb *tcp, long arg);

#include "xlat/msgctl_flags.h"
#include "xlat/semctl_flags.h"
#include "xlat/shmctl_flags.h"
#include "xlat/resource_flags.h"
#include "xlat/shm_resource_flags.h"
#include "xlat/shm_flags.h"
#include "xlat/ipc_msg_flags.h"
#include "xlat/semop_flags.h"

SYS_FUNC(msgget)
{
	if (tcp->u_arg[0])
		tprintf("%#lx, ", tcp->u_arg[0]);
	else
		tprints("IPC_PRIVATE, ");
	if (printflags(resource_flags, tcp->u_arg[1] & ~0777, NULL) != 0)
		tprints("|");
	tprintf("%#lo", tcp->u_arg[1] & 0777);
	return RVAL_DECODED;
}

#ifdef IPC_64
# define PRINTCTL(flagset, arg, dflt) \
	if ((arg) & IPC_64) tprints("IPC_64|"); \
	printxval((flagset), (arg) &~ IPC_64, dflt)
#else
# define PRINTCTL printxval
#endif

static int
indirect_ipccall(struct tcb *tcp)
{
	return tcp->s_ent->sys_flags & TRACE_INDIRECT_SUBCALL;
}

SYS_FUNC(msgctl)
{
	tprintf("%lu, ", tcp->u_arg[0]);
	PRINTCTL(msgctl_flags, tcp->u_arg[1], "MSG_???");
	tprints(", ");
	printaddr(tcp->u_arg[indirect_ipccall(tcp) ? 3 : 2]);
	return RVAL_DECODED;
}

static void
tprint_msgbuf(struct tcb *tcp, const long addr, const unsigned long count)
{
	long mtype;

	if (!umove_or_printaddr(tcp, addr, &mtype)) {
		tprintf("{%lu, ", mtype);
		printstr(tcp, addr + sizeof(mtype), count);
		tprints("}");
	}
	tprintf(", %lu, ", count);
}

static void
tprint_msgsnd(struct tcb *tcp, const long addr, const unsigned long count,
	      const unsigned long flags)
{
	tprint_msgbuf(tcp, addr, count);
	printflags(ipc_msg_flags, flags, "MSG_???");
}

SYS_FUNC(msgsnd)
{
	tprintf("%d, ", (int) tcp->u_arg[0]);
	if (indirect_ipccall(tcp)) {
		tprint_msgsnd(tcp, tcp->u_arg[3], tcp->u_arg[1],
			      tcp->u_arg[2]);
	} else {
		tprint_msgsnd(tcp, tcp->u_arg[1], tcp->u_arg[2],
			      tcp->u_arg[3]);
	}
	return RVAL_DECODED;
}

static void
tprint_msgrcv(struct tcb *tcp, const long addr, const unsigned long count,
	      const long msgtyp)
{
	tprint_msgbuf(tcp, addr, count);
	tprintf("%ld, ", msgtyp);
}

SYS_FUNC(msgrcv)
{
	if (entering(tcp)) {
		tprintf("%d, ", (int) tcp->u_arg[0]);
	} else {
		if (indirect_ipccall(tcp)) {
			struct ipc_wrapper {
				struct msgbuf *msgp;
				long msgtyp;
			} tmp;

			if (umove_or_printaddr(tcp, tcp->u_arg[3], &tmp))
				tprintf(", %lu, ", tcp->u_arg[1]);
			else
				tprint_msgrcv(tcp, (long) tmp.msgp,
					tcp->u_arg[1], tmp.msgtyp);
			printflags(ipc_msg_flags, tcp->u_arg[2], "MSG_???");
		} else {
			tprint_msgrcv(tcp, tcp->u_arg[1],
				tcp->u_arg[2], tcp->u_arg[3]);
			printflags(ipc_msg_flags, tcp->u_arg[4], "MSG_???");
		}
	}
	return 0;
}

#if defined(HAVE_SYS_SHM_H) || defined(HAVE_LINUX_SEM_H)
static void
tprint_sembuf(const struct sembuf *sb)
{
	tprintf("{%u, %d, ", sb->sem_num, sb->sem_op);
	printflags(semop_flags, sb->sem_flg, "SEM_???");
	tprints("}");
}
#endif

static void
tprint_sembuf_array(struct tcb *tcp, const long addr, const unsigned long count)
{
#if defined(HAVE_SYS_SHM_H) || defined(HAVE_LINUX_SEM_H)
	unsigned long max_count;
	struct sembuf sb;

	if (abbrev(tcp))
		max_count = (max_strlen < count) ? max_strlen : count;
	else
		max_count = count;

	if (!max_count)
		printaddr(addr);
	else if (!umove_or_printaddr(tcp, addr, &sb)) {
		unsigned long i;

		tprints("[");
		tprint_sembuf(&sb);

		for (i = 1; i < max_count; ++i) {
			tprints(", ");
			if (umove_or_printaddr(tcp, addr + i * sizeof(sb), &sb))
				break;
			else
				tprint_sembuf(&sb);
		}

		if (i < max_count || max_count < count)
			tprints(", ...");

		tprints("]");
	}
#else
	printaddr(addr);
#endif
	tprintf(", %lu", count);
}

SYS_FUNC(semop)
{
	tprintf("%lu, ", tcp->u_arg[0]);
	if (indirect_ipccall(tcp)) {
		tprint_sembuf_array(tcp, tcp->u_arg[3], tcp->u_arg[1]);
	} else {
		tprint_sembuf_array(tcp, tcp->u_arg[1], tcp->u_arg[2]);
	}
	return RVAL_DECODED;
}

SYS_FUNC(semtimedop)
{
	tprintf("%lu, ", tcp->u_arg[0]);
	if (indirect_ipccall(tcp)) {
		tprint_sembuf_array(tcp, tcp->u_arg[3], tcp->u_arg[1]);
		tprints(", ");
#if defined(S390) || defined(S390X)
		printtv(tcp, tcp->u_arg[2]);
#else
		printtv(tcp, tcp->u_arg[4]);
#endif
	} else {
		tprint_sembuf_array(tcp, tcp->u_arg[1], tcp->u_arg[2]);
		tprints(", ");
		printtv(tcp, tcp->u_arg[3]);
	}
	return RVAL_DECODED;
}

SYS_FUNC(semget)
{
	if (tcp->u_arg[0])
		tprintf("%#lx", tcp->u_arg[0]);
	else
		tprints("IPC_PRIVATE");
	tprintf(", %lu, ", tcp->u_arg[1]);
	if (printflags(resource_flags, tcp->u_arg[2] & ~0777, NULL) != 0)
		tprints("|");
	tprintf("%#lo", tcp->u_arg[2] & 0777);
	return RVAL_DECODED;
}

SYS_FUNC(semctl)
{
	tprintf("%lu, %lu, ", tcp->u_arg[0], tcp->u_arg[1]);
	PRINTCTL(semctl_flags, tcp->u_arg[2], "SEM_???");
	tprints(", ");
	if (indirect_ipccall(tcp)) {
		if (current_wordsize == sizeof(int))
			printnum_int(tcp, tcp->u_arg[3], "%#x");
		else
			printnum_long(tcp, tcp->u_arg[3], "%#lx");
	} else {
		tprintf("%#lx", tcp->u_arg[3]);
	}
	return RVAL_DECODED;
}

SYS_FUNC(shmget)
{
	if (tcp->u_arg[0])
		tprintf("%#lx", tcp->u_arg[0]);
	else
		tprints("IPC_PRIVATE");
	tprintf(", %lu, ", tcp->u_arg[1]);
	if (printflags(shm_resource_flags, tcp->u_arg[2] & ~0777, NULL) != 0)
		tprints("|");
	tprintf("%#lo", tcp->u_arg[2] & 0777);
	return RVAL_DECODED;
}

SYS_FUNC(shmctl)
{
	tprintf("%lu, ", tcp->u_arg[0]);
	PRINTCTL(shmctl_flags, tcp->u_arg[1], "SHM_???");
	tprints(", ");
	printaddr(tcp->u_arg[indirect_ipccall(tcp) ? 3 : 2]);
	return RVAL_DECODED;
}

SYS_FUNC(shmat)
{
	if (entering(tcp)) {
		tprintf("%lu, ", tcp->u_arg[0]);
		if (indirect_ipccall(tcp)) {
			printaddr(tcp->u_arg[3]);
			tprints(", ");
			printflags(shm_flags, tcp->u_arg[1], "SHM_???");
		} else {
			printaddr(tcp->u_arg[1]);
			tprints(", ");
			printflags(shm_flags, tcp->u_arg[2], "SHM_???");
		}
		return 0;
	} else {
		if (syserror(tcp))
			return 0;
		if (indirect_ipccall(tcp)) {
			unsigned long raddr;
			if (umove(tcp, tcp->u_arg[2], &raddr) < 0)
				return RVAL_NONE;
			tcp->u_rval = raddr;
		}
		return RVAL_HEX;
	}
}

SYS_FUNC(shmdt)
{
	printaddr(tcp->u_arg[indirect_ipccall(tcp) ? 3 : 0]);
	return RVAL_DECODED;
}

SYS_FUNC(mq_open)
{
	printpath(tcp, tcp->u_arg[0]);
	tprints(", ");
	/* flags */
	tprint_open_modes(tcp->u_arg[1]);
	if (tcp->u_arg[1] & O_CREAT) {
		/* mode */
		tprintf(", %#lo, ", tcp->u_arg[2]);
# if !defined(HAVE_MQUEUE_H) && !defined(HAVE_LINUX_MQUEUE_H)
		printaddr(tcp->u_arg[3]);
# else
		struct mq_attr attr;

		if (!umove_or_printaddr(tcp, tcp->u_arg[3], &attr))
			tprintf("{mq_maxmsg=%ld, mq_msgsize=%ld}",
				(long) attr.mq_maxmsg,
				(long) attr.mq_msgsize);
# endif
	}
	return RVAL_DECODED;
}

SYS_FUNC(mq_timedsend)
{
	tprintf("%ld, ", tcp->u_arg[0]);
	printstr(tcp, tcp->u_arg[1], tcp->u_arg[2]);
	tprintf(", %lu, %ld, ", tcp->u_arg[2], tcp->u_arg[3]);
	printtv(tcp, tcp->u_arg[4]);
	return RVAL_DECODED;
}

SYS_FUNC(mq_timedreceive)
{
	if (entering(tcp))
		tprintf("%ld, ", tcp->u_arg[0]);
	else {
		printstr(tcp, tcp->u_arg[1], tcp->u_arg[2]);
		tprintf(", %lu, %ld, ", tcp->u_arg[2], tcp->u_arg[3]);
		printtv(tcp, tcp->u_arg[4]);
	}
	return 0;
}

SYS_FUNC(mq_notify)
{
	tprintf("%ld, ", tcp->u_arg[0]);
	printsigevent(tcp, tcp->u_arg[1]);
	return RVAL_DECODED;
}

static void
printmqattr(struct tcb *tcp, const long addr)
{
# if !defined(HAVE_MQUEUE_H) && !defined(HAVE_LINUX_MQUEUE_H)
	printaddr(addr);
# else
	struct mq_attr attr;
	if (umove_or_printaddr(tcp, addr, &attr))
		return;
	tprints("{mq_flags=");
	tprint_open_modes(attr.mq_flags);
	tprintf(", mq_maxmsg=%ld, mq_msgsize=%ld, mq_curmsg=%ld}",
		(long) attr.mq_maxmsg, (long) attr.mq_msgsize,
		(long) attr.mq_curmsgs);
# endif
}

SYS_FUNC(mq_getsetattr)
{
	if (entering(tcp)) {
		tprintf("%ld, ", tcp->u_arg[0]);
		printmqattr(tcp, tcp->u_arg[1]);
		tprints(", ");
	} else
		printmqattr(tcp, tcp->u_arg[2]);
	return 0;
}
=======
>>>>>>> BRANCH (bab4ef tests: add ksysent.test)
