/* Generated by ./xlat/gen.sh from ./xlat/sched_flags.in; do not edit. */

#include "gcc_compat.h"
#include "static_assert.h"

#if defined(SCHED_FLAG_RESET_ON_FORK) || (defined(HAVE_DECL_SCHED_FLAG_RESET_ON_FORK) && HAVE_DECL_SCHED_FLAG_RESET_ON_FORK)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((SCHED_FLAG_RESET_ON_FORK) == (1), "SCHED_FLAG_RESET_ON_FORK != 1");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define SCHED_FLAG_RESET_ON_FORK 1
#endif
#if defined(SCHED_FLAG_RECLAIM) || (defined(HAVE_DECL_SCHED_FLAG_RECLAIM) && HAVE_DECL_SCHED_FLAG_RECLAIM)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((SCHED_FLAG_RECLAIM) == (2), "SCHED_FLAG_RECLAIM != 2");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define SCHED_FLAG_RECLAIM 2
#endif
#if defined(SCHED_FLAG_DL_OVERRUN) || (defined(HAVE_DECL_SCHED_FLAG_DL_OVERRUN) && HAVE_DECL_SCHED_FLAG_DL_OVERRUN)
DIAG_PUSH_IGNORE_TAUTOLOGICAL_COMPARE
static_assert((SCHED_FLAG_DL_OVERRUN) == (4), "SCHED_FLAG_DL_OVERRUN != 4");
DIAG_POP_IGNORE_TAUTOLOGICAL_COMPARE
#else
# define SCHED_FLAG_DL_OVERRUN 4
#endif

#ifndef XLAT_MACROS_ONLY

# ifdef IN_MPERS

#  error static const struct xlat sched_flags in mpers mode

# else

static
const struct xlat sched_flags[] = {
 XLAT(SCHED_FLAG_RESET_ON_FORK),
 XLAT(SCHED_FLAG_RECLAIM),
 XLAT(SCHED_FLAG_DL_OVERRUN),
 XLAT_END
};

# endif /* !IN_MPERS */

#endif /* !XLAT_MACROS_ONLY */