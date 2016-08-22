// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/quote.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/list/list.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, VAL(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, NUM(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, PAIR(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LIST(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, MAP(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LBD(M)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::quote>, LBD(_)>), (TRUE)); \
    CHECK((metal::invoke<metal::quote<VAL(M)> COMMA(N) VALS(N)>), (VAL(M))); \
    CHECK((metal::invoke<metal::quote<NUM(M)> COMMA(N) VALS(N)>), (NUM(M))); \
    CHECK((metal::invoke<metal::quote<PAIR(M)> COMMA(N) VALS(N)>), (PAIR(M))); \
    CHECK((metal::invoke<metal::quote<LIST(M)> COMMA(N) VALS(N)>), (LIST(M))); \
    CHECK((metal::invoke<metal::quote<MAP(M)> COMMA(N) VALS(N)>), (MAP(M))); \
    CHECK((metal::invoke<metal::quote<LBD(M)> COMMA(N) VALS(N)>), (LBD(M))); \
    CHECK((metal::invoke<metal::quote<LBD(_)> COMMA(N) VALS(N)>), (LBD(_))); \
/**/

GEN(MATRIX)