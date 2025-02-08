/*
 * Port from mingw-w64-headers/crt/dirent.h
 *
 * DIRENT.H (formerly DIRLIB.H)
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 */

#ifndef _DIRENT_H_
#define _DIRENT_H_

#ifndef _MSC_VER
# error this dirent.h implementation is for MSVC or MSVC-like toolset only!
#endif /* _MSC_VER */

#include <io.h>
#include "mspcrt.h"

__BEGIN_DECLS

#ifndef RC_INVOKED

#pragma pack(push,_CRT_PACKING)

struct dirent
{
	long		d_ino;		/* Always zero. */
	unsigned short	d_reclen;	/* Always zero. */
	unsigned short	d_namlen;	/* Length of name in d_name. */
	char		d_name[260]; /* [FILENAME_MAX] */ /* File name. */
};

/*
 * This is an internal data structure. Good programmers will not use it
 * except as an argument to one of the functions below.
 * dd_stat field is now int (was short in older versions).
 */
typedef struct
{
	/* disk transfer area for this dir */
	struct _finddata_t	dd_dta;

	/* dirent struct to return from dir (NOTE: this makes this thread
	 * safe as long as only one thread uses a particular DIR struct at
	 * a time) */
	struct dirent		dd_dir;

	/* _findnext handle */
	intptr_t		dd_handle;

	/*
	 * Status of search:
	 *   0 = not started yet (next entry to read is first entry)
	 *  -1 = off the end
	 *   positive = 0 based index of next entry
	 */
	int			dd_stat;

	/* given path for dir with search pattern (struct is extended) */
	char			dd_name[1];
} DIR;

_PCRTIMP DIR* __cdecl opendir (const char*);
_PCRTIMP struct dirent* __cdecl readdir (DIR*);
_PCRTIMP int __cdecl closedir (DIR*);
_PCRTIMP void __cdecl rewinddir (DIR*);
_PCRTIMP long __cdecl telldir (DIR*);
_PCRTIMP void __cdecl seekdir (DIR*, long);

/* wide char versions */

struct _wdirent
{
	long		d_ino;		/* Always zero. */
	unsigned short	d_reclen;	/* Always zero. */
	unsigned short	d_namlen;	/* Length of name in d_name. */
	wchar_t		d_name[260]; /* [FILENAME_MAX] */ /* File name. */
};

/*
 * This is an internal data structure. Good programmers will not use it
 * except as an argument to one of the functions below.
 */
typedef struct
{
	/* disk transfer area for this dir */
	struct _wfinddata_t	dd_dta;

	/* dirent struct to return from dir (NOTE: this makes this thread
	 * safe as long as only one thread uses a particular DIR struct at
	 * a time) */
	struct _wdirent		dd_dir;

	/* _findnext handle */
	intptr_t		dd_handle;

	/*
	 * Status of search:
	 *   0 = not started yet (next entry to read is first entry)
	 *  -1 = off the end
	 *   positive = 0 based index of next entry
	 */
	int			dd_stat;

	/* given path for dir with search pattern (struct is extended) */
	wchar_t			dd_name[1];
} _WDIR;

_PCRTIMP _WDIR* __cdecl _wopendir (const wchar_t*);
_PCRTIMP struct _wdirent* __cdecl _wreaddir (_WDIR*);
_PCRTIMP int __cdecl _wclosedir (_WDIR*);
_PCRTIMP void __cdecl _wrewinddir (_WDIR*);
_PCRTIMP long __cdecl _wtelldir (_WDIR*);
_PCRTIMP void __cdecl _wseekdir (_WDIR*, long);

#pragma pack(pop)

#endif	/* Not RC_INVOKED */

__END_DECLS

#endif	/* Not _DIRENT_H_ */
