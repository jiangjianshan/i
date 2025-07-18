/*
   Port from gnulib/lib/popen.c

   Open a stream to a sub-process.
   Copyright (C) 2009-2025 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Eric Blake <ebb9@byu.net>, 2009.  */

/* Specification.  */
#include <stdio.h>

#if defined _WIN32 && ! defined __CYGWIN__
/* Native Windows API.  */

# include <string.h>

FILE *
popen (const char *filename, const char *mode)
{
  /* Use binary mode by default.  */
  if (strcmp (mode, "r") == 0)
    mode = "rb";
  else if (strcmp (mode, "w") == 0)
    mode = "wb";

  return _popen (filename, mode);
}

#endif
