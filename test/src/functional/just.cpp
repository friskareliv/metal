// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/functional/just.hpp>
#include <metal/functional/traits/is_just.hpp>

#include "test.hpp"

using namespace metal;

METAL_TEST_ASSERT((is_just_t<just<test::a0>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a1>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a2>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a3>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a4>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a5>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a6>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a7>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a8>>::value));
METAL_TEST_ASSERT((is_just_t<just<test::a9>>::value));

METAL_TEST_ASSERT((std::is_same<just<test::a0>::type, test::a0>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a1>::type, test::a1>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a2>::type, test::a2>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a3>::type, test::a3>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a4>::type, test::a4>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a5>::type, test::a5>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a6>::type, test::a6>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a7>::type, test::a7>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a8>::type, test::a8>::value));
METAL_TEST_ASSERT((std::is_same<just<test::a9>::type, test::a9>::value));

METAL_TEST_ASSERT((!std::is_same<just<test::a0>::type, test::a9>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a1>::type, test::a0>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a2>::type, test::a1>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a3>::type, test::a2>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a4>::type, test::a3>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a5>::type, test::a4>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a6>::type, test::a5>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a7>::type, test::a6>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a8>::type, test::a7>::value));
METAL_TEST_ASSERT((!std::is_same<just<test::a9>::type, test::a8>::value));