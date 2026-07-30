/* z/OS type fixup header for libgit2
 * Force-included to provide ssize_t and SIZE_MAX when using
 * ibm-clang64 with zoslib and _XOPEN_SOURCE=600.
 *
 * Root cause: On z/OS, the zopen prefix (/usr/local/include) and the
 * zoslib include path both contain a sys/types.h wrapper that uses the
 * same include guard (ZOS_SYS_TYPES_H). When both are in the -isystem
 * path, the guard collision prevents the system sys/types.h from being
 * reached via -include sys/types.h, so ssize_t and SIZE_MAX are never
 * defined.
 *
 * Fix: define ssize_t directly (matching the system definition for LP64)
 * and include stdint.h (which is not wrapped by zoslib) to get SIZE_MAX.
 */
#ifndef ZOS_TYPES_FIXUP_H_
#define ZOS_TYPES_FIXUP_H_

#ifndef __ssize_t
# ifdef _LP64
typedef signed long ssize_t;
# else
typedef signed int ssize_t;
# endif
# define __ssize_t 1
#endif

/* SIZE_MAX is defined by stdint.h (C99); stdint.h is not wrapped by
 * zoslib so the system version is always reached cleanly. */
#include <stdint.h>

#endif /* ZOS_TYPES_FIXUP_H_ */
