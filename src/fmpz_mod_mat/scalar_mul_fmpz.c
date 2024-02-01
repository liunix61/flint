/*
    Copyright (C) 2017 Luca De Feo

    This file is part of FLINT.

    FLINT is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License (LGPL) as published
    by the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.  See <https://www.gnu.org/licenses/>.
*/

#include "fmpz.h"
#include "fmpz_mod.h"
#include "fmpz_mod_mat.h"

void fmpz_mod_mat_scalar_mul_fmpz(fmpz_mod_mat_t B, const fmpz_mod_mat_t A, fmpz_t c, const fmpz_mod_ctx_t ctx)
{
    fmpz_t d;
    fmpz_init(d);
    fmpz_mod_set_fmpz(d, c, ctx);
    fmpz_mat_scalar_mul_fmpz(B, A, d);
    _fmpz_mod_mat_reduce(B, ctx);
    fmpz_clear(d);
}
