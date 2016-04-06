/*
 * Copyright (c) 2016 Dmitry V. Levin <ldv@altlinux.org>
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

#ifndef TESTS_H_
# define TESTS_H_

# ifdef HAVE_CONFIG_H
#  include "config.h"
# endif

# include <sys/types.h>
# include "gcc_compat.h"

/* Cached sysconf(_SC_PAGESIZE). */
size_t get_page_size(void);

/* Print message and strerror(errno) to stderr, then exit(1). */
void perror_msg_and_fail(const char *, ...)
	ATTRIBUTE_FORMAT((printf, 1, 2)) ATTRIBUTE_NORETURN;
/* Print message to stderr, then exit(1). */
void error_msg_and_fail(const char *, ...)
	ATTRIBUTE_FORMAT((printf, 1, 2)) ATTRIBUTE_NORETURN;
/* Print message to stderr, then exit(77). */
void error_msg_and_skip(const char *, ...)
	ATTRIBUTE_FORMAT((printf, 1, 2)) ATTRIBUTE_NORETURN;
/* Print message and strerror(errno) to stderr, then exit(77). */
void perror_msg_and_skip(const char *, ...)
	ATTRIBUTE_FORMAT((printf, 1, 2)) ATTRIBUTE_NORETURN;

/*
 * Allocate memory that ends on the page boundary.
 * Pages allocated by this call are preceeded by an unmapped page
 * and followed also by an unmapped page.
 */
void *tail_alloc(const size_t)
	ATTRIBUTE_MALLOC ATTRIBUTE_ALLOC_SIZE((1));
/* Allocate memory using tail_alloc, then memcpy. */
void *tail_memdup(const void *, const size_t)
	ATTRIBUTE_MALLOC ATTRIBUTE_ALLOC_SIZE((2));

/* Close stdin, move stdout to a non-standard descriptor, and print. */
void tprintf(const char *, ...)
	ATTRIBUTE_FORMAT((printf, 1, 2));

/* Make a hexdump copy of C string */
const char *hexdump_strdup(const char *);

/* Make a hexdump copy of memory */
const char *hexdump_memdup(const char *, size_t);

/* Make a hexquoted copy of a string */
const char *hexquote_strndup(const char *, size_t);

/* Return inode number of socket descriptor. */
unsigned long inode_of_sockfd(int);

/* Print string in quoted form. */
void print_quoted_string(const char *str);

# define ARRAY_SIZE(arg) ((unsigned int) (sizeof(arg) / sizeof((arg)[0])))
# define LENGTH_OF(arg) ((unsigned int) sizeof(arg) - 1)

# define SKIP_MAIN_UNDEFINED(arg) \
	int main(void) { error_msg_and_skip("undefined: %s", arg); }

#endif
