/* kitty: C++ truth table library
 * Copyright (C) 2017  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <benchmark/benchmark.h>

#include <kitty/kitty.hpp>

using namespace kitty;

void BM_exact_npn_canonization_static( benchmark::State& state )
{
  while ( state.KeepRunning() )
  {
    static_truth_table<6> tt;
    create_from_hex_string( tt, "17cad20f55459c3f" );
    exact_npn_canonization( tt );
  }
}

void BM_exact_npn_canonization_dynamic( benchmark::State& state )
{
  while ( state.KeepRunning() )
  {
    dynamic_truth_table tt( 6 );
    create_from_hex_string( tt, "17cad20f55459c3f" );
    exact_npn_canonization( tt );
  }
}

BENCHMARK( BM_exact_npn_canonization_static );
BENCHMARK( BM_exact_npn_canonization_dynamic );

BENCHMARK_MAIN()