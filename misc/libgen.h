/**
 * Port from mingw-w64-headers/crt/libgen.h
 *
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _LIBGEN_H_
#define _LIBGEN_H_

#ifndef _MSC_VER
# error this libgen.h implementation is for MSVC or MSVC-like toolset only!
#endif /* _MSC_VER */

#include "mspcrt.h"

__BEGIN_DECLS

_PCRTIMP char * __cdecl basename (char *);
_PCRTIMP char * __cdecl dirname (char *);

__END_DECLS

#endif
