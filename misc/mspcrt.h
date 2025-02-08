/*
 * Copyright (c) 2024 Jianshan Jiang
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _PCRT_H
#define _PCRT_H

#include <stdio.h>

/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef __cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#if defined(PCRT_SHARED)
# if defined(DLL_EXPORT)
#  define _PCRTIMP __declspec(dllexport)
# else
#  define _PCRTIMP __declspec(dllimport)
# endif /* DLL_EXPORT */
#else
# define _PCRTIMP
#endif /* PCRT_SHARED */

__BEGIN_DECLS

/* dirent structures and functions in tchar.h, but MSVC is missing */
#ifdef _UNICODE
# define _tdirent	    _wdirent
# define _TDIR 		    _WDIR
# define _topendir	  _wopendir
# define _tclosedir	  _wclosedir
# define _treaddir	  _wreaddir
# define _trewinddir  _wrewinddir
# define _ttelldir	  _wtelldir
# define _tseekdir	  _wseekdir
#else
# define _tdirent	    dirent
# define _TDIR 		    DIR
# define _topendir	  opendir
# define _tclosedir	  closedir
# define _treaddir	  readdir
# define _trewinddir	rewinddir
# define _ttelldir	  telldir
# define _tseekdir	  seekdir
#endif /* _UNICODE */

/*
  Documentation for these POSIX definitions and prototypes can be found in
  The Open Group Base Specifications Issue 6
  IEEE Std 1003.1, 2004 Edition.
  eg:  http://www.opengroup.org/onlinepubs/009695399/functions/twalk.html
*/
typedef struct entry {
	char *key;
	void *data;
} ENTRY;

typedef enum {
	FIND,
	ENTER
} ACTION;

typedef enum {
	preorder,
	postorder,
	endorder,
	leaf
} VISIT;

#ifdef _SEARCH_PRIVATE
typedef struct node {
	char         *key;
	struct node  *llink, *rlink;
} node_t;
#endif /* _SEARCH_PRIVATE */
_PCRTIMP void * __cdecl tdelete (const void * __restrict, void ** __restrict, int (*)(const void *, const void *));
_PCRTIMP void * __cdecl tfind (const void *, void * const *, int (*)(const void *, const void *));
_PCRTIMP void * __cdecl tsearch (const void *, void **, int (*)(const void *, const void *));
_PCRTIMP void __cdecl twalk (const void *, void (*)(const void *, VISIT, int));
#ifdef _GNU_SOURCE
_PCRTIMP void __cdecl tdestroy(void *, void (*)(void *));
#endif /* _GNU_SOURCE */

/* missing definitions in sys/types.h */
#ifndef __NO_ISOCEXT
typedef unsigned int useconds_t;
#endif

/* missing types definitions */
typedef long off32_t;
typedef long long off64_t;

/* missing types definitions in time.h */
#ifdef _WIN64
typedef __int64 ssize_t;
#else
typedef int ssize_t;
#endif

/* missing function prototypes in io.h */
_PCRTIMP char *getlogin(void);

/* missing function prototypes in stdio.h */
_PCRTIMP FILE *popen (const char *filename, const char *mode);
_PCRTIMP int pclose (FILE *stream);

__END_DECLS

#endif /* _PCRT_H */
