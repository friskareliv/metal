// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/pair/pair.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, VAL(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, NUM(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, PAIR(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LIST(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, MAP(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), VAL(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(M), LBD(_)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), NUM(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), PAIR(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), LIST(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), MAP(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), LBD(N)>), (TRUE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::pair>, LBD(_), LBD(_)>), (TRUE)); \
    CHECK((metal::is_pair<VAL(N)>), (FALSE)); \
    CHECK((metal::is_pair<NUM(N)>), (FALSE)); \
    CHECK((metal::is_pair<PAIR(N)>), (TRUE)); \
    CHECK((metal::is_pair<LIST(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_pair<MAP(N)>), (BOOL(N == 2))); \
    CHECK((metal::is_pair<LBD(N)>), (FALSE)); \
    CHECK((metal::is_pair<LBD(_)>), (FALSE)); \
/**/

GEN(MATRIX)