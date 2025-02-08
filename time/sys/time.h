/**
 * Port from mingw-w64-headers/crt/sys/time.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _SYS_TIME_H_
#define _SYS_TIME_H_

#ifndef _MSC_VER
# error this sys/time.h implementation is for MSVC or MSVC-like toolset only!
#endif /* _MSC_VER */

#include "mspcrt.h"
#include <time.h>

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <winsock2.h>

__BEGIN_DECLS

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
_PCRTIMP int __cdecl gettimeofday(struct timeval *__restrict, void *__restrict);

__END_DECLS

/* Adding timespec definition.  */
#include <sys/timeb.h>

#endif /* _SYS_TIME_H_ */
