/* Generated by ./xlat/gen.sh from ./xlat/netlink_types.in; do not edit. */

#include "gcc_compat.h"
#include "static_assert.h"

#if defined(NLMSG_NOOP) || (defined(HAVE_DECL_NLMSG_NOOP) && HAVE_DECL_NLMSG_NOOP)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((NLMSG_NOOP) == (0x1), "NLMSG_NOOP != 0x1");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define NLMSG_NOOP 0x1
#endif
#if defined(NLMSG_ERROR) || (defined(HAVE_DECL_NLMSG_ERROR) && HAVE_DECL_NLMSG_ERROR)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((NLMSG_ERROR) == (0x2), "NLMSG_ERROR != 0x2");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define NLMSG_ERROR 0x2
#endif
#if defined(NLMSG_DONE) || (defined(HAVE_DECL_NLMSG_DONE) && HAVE_DECL_NLMSG_DONE)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((NLMSG_DONE) == (0x3), "NLMSG_DONE != 0x3");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define NLMSG_DONE 0x3
#endif
#if defined(NLMSG_OVERRUN) || (defined(HAVE_DECL_NLMSG_OVERRUN) && HAVE_DECL_NLMSG_OVERRUN)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((NLMSG_OVERRUN) == (0x4), "NLMSG_OVERRUN != 0x4");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define NLMSG_OVERRUN 0x4
#endif

#ifndef XLAT_MACROS_ONLY

# ifdef IN_MPERS

#  error static const struct xlat netlink_types in mpers mode

# else

static
const struct xlat netlink_types[] = {
 XLAT(NLMSG_NOOP),
 XLAT(NLMSG_ERROR),
 XLAT(NLMSG_DONE),
 XLAT(NLMSG_OVERRUN),
 XLAT_END
};

# endif /* !IN_MPERS */

#endif /* !XLAT_MACROS_ONLY */