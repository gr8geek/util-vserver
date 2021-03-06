// $Id$    --*- c -*--

// Copyright (C) 2004 Enrico Scholz <enrico.scholz@informatik.tu-chemnitz.de>
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; version 2 of the License.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//  
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.


#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "vserver.h"
#include <string.h>
#include <stdlib.h>

bool
vc_parseLimit(char const *buf, vc_limit_t *res)
{
  char *	errptr;
  
  if (strncmp(buf, "inf", 3)==0) {
    *res = VC_LIM_INFINITY;
    return true;
  }
  
  *res = strtoll(buf, &errptr, 0);

  if (errptr!=buf) {
    switch (*errptr) {
      case 'M'	:  *res *= 1024; /* fallthrough */
      case 'K'	:  *res *= 1024; ++errptr; break;
      case 'm'	:  *res *= 1000; /* fallthrough */
      case 'k'	:  *res *= 1000; ++errptr; break;
      default	:  break;
    }
  }

  return errptr!=buf && (*errptr=='\0' || *errptr=='\n');
}
