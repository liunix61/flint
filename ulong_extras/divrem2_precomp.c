/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2009 William Hart

*****************************************************************************/

#include <mpir.h>
#include "flint.h"
#include "ulong_extras.h"

mp_limb_t n_divrem2_precomp(mp_limb_t * q, mp_limb_t a, mp_limb_t n, double npre)
{
   if (a < n) 
   {
      (*q) = 0UL;
      return a;
   }

   if ((mp_limb_signed_t) n < 0L) 
   {
      (*q) = 1UL;
      return a - n;
   }

   mp_limb_t quot = (mp_limb_t) ((double) a * npre);
   long rem = a - quot*n;
   if (rem < (mp_limb_signed_t)(-n)) quot -= (mp_limb_t) ((double) (-rem) * npre);
   else if (rem >= (long) n) quot += (mp_limb_t) ((double) rem * npre);
   else if (rem < 0L) 
   {
      (*q) = quot - 1;
      return rem + n;
   } else 
   {
      (*q) = quot;
      return rem;
   }
   
   rem = a - quot*n;
   if (rem >= (long) n) 
   {
      (*q) = quot + 1;
      return rem - n;
   } else if (rem < 0L) 
   {
      (*q) = quot - 1;
      return rem + n;
   } else 
   {
      (*q) = quot;
      return rem;
   }
}

