/* Copyright (C) 2019-2020 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _UNISTD_H
# error "Never include this file directly.  Use <unistd.h> instead"
#endif

#include <bits/wordsize.h>

/* This header should define the following symbols under the described
   situations.  A value `1' means that the model is always supported,
   `-1' means it is never supported.  Undefined means it cannot be
   statically decided.

   _POSIX_V7_ILP32_OFF32   32bit int, long, pointers, and off_t type
   _POSIX_V7_ILP32_OFFBIG  32bit int, long, and pointers and larger off_t type

   _POSIX_V7_LP64_OFF32	   64bit long and pointers and 32bit off_t type
   _POSIX_V7_LPBIG_OFFBIG  64bit long and pointers and large off_t type

   The macros _POSIX_V6_ILP32_OFF32, _POSIX_V6_ILP32_OFFBIG,
   _POSIX_V6_LP64_OFF32, _POSIX_V6_LPBIG_OFFBIG, _XBS5_ILP32_OFF32,
   _XBS5_ILP32_OFFBIG, _XBS5_LP64_OFF32, and _XBS5_LPBIG_OFFBIG were
   used in previous versions of the Unix standard and are available
   only for compatibility.
*/

#if __WORDSIZE == 64

/* We can never provide environments with 32-bit wide pointers.  */
# define _POSIX_V7_ILP32_OFF32	-1
# define _POSIX_V7_ILP32_OFFBIG	-1
# define _POSIX_V6_ILP32_OFF32	-1
# define _POSIX_V6_ILP32_OFFBIG	-1
# define _XBS5_ILP32_OFF32	-1
# define _XBS5_ILP32_OFFBIG	-1
/* We also have no use (for now) for an environment with bigger pointers
   and offsets.  */
# define _POSIX_V7_LPBIG_OFFBIG	-1
# define _POSIX_V6_LPBIG_OFFBIG	-1
# define _XBS5_LPBIG_OFFBIG	-1

/* By default we have 64-bit wide `long int', pointers and `off_t'.  */
# define _POSIX_V7_LP64_OFF64	1
# define _POSIX_V6_LP64_OFF64	1
# define _XBS5_LP64_OFF64	1

#else /* __WORDSIZE == 32 */

/* RISC-V requires 64-bit off_t
  # undef _POSIX_V7_ILP32_OFF32
  # undef _POSIX_V6_ILP32_OFF32
  # undef _XBS5_ILP32_OFF32
 */

# define _POSIX_V7_ILP32_OFFBIG  1
# define _POSIX_V6_ILP32_OFFBIG  1
# define _XBS5_ILP32_OFFBIG   1

/* We can never provide environments with 64-bit wide pointers.  */
# define _POSIX_V7_LP64_OFF64	-1
# define _POSIX_V7_LPBIG_OFFBIG	-1
# define _POSIX_V6_LP64_OFF64	-1
# define _POSIX_V6_LPBIG_OFFBIG	-1
# define _XBS5_LP64_OFF64	-1
# define _XBS5_LPBIG_OFFBIG	-1

/* CFLAGS.  */
#define __ILP32_OFFBIG_CFLAGS   "-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64"

#endif /* __WORDSIZE == 32 */
