// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/list/slice.hpp>
#include <metal/list/list.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/number/number.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<VALUES(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<NUMBERS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<PAIRS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<LISTS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<MAPS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, VALUE(M), metal::list<LAMBDAS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<VALUES(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<NUMBERS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<PAIRS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<LISTS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<MAPS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, NUMBER(M), metal::list<LAMBDAS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<VALUES(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<NUMBERS(N)>>), (BOOL(N < 3))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<PAIRS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<LISTS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<MAPS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, PAIR(M), metal::list<LAMBDAS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<VALUES(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<NUMBERS(N)>>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<PAIRS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<LISTS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<MAPS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LIST(M), metal::list<LAMBDAS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<VALUES(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<NUMBERS(N)>>), (BOOL(M >= N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<PAIRS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<LISTS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<MAPS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, MAP(M), metal::list<LAMBDAS(N)>>), (BOOL(!N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<VALUES(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<NUMBERS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<PAIRS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<LISTS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<MAPS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(M), metal::list<LAMBDAS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<VALUES(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<NUMBERS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<PAIRS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<LISTS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<MAPS(N)>>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::slice>, LAMBDA(_), metal::list<LAMBDAS(N)>>), (FALSE)); \
    CHECK((metal::slice<LIST(INF), metal::list<ENUM(N, NUMBER FIX(M))>>), (metal::list<ENUM(N, VALUE FIX(M))>)); \
/**/

GEN(MATRIX)
