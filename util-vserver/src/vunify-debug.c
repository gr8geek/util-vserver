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

#include "vunify-matchlist.h"

void
MatchList_destroy(struct MatchList *list)
{
  size_t		i;

  String_destroy(&list->id);
  free(list->data);

  for (i=0; i<list->buf_count; ++i)
    free(const_cast(void *)(list->buf[i]));

  free(list->buf);
}

void
String_destroy(String *str)
{
  free(const_cast(char *)(str->d));
}
