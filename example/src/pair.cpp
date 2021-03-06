// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal.hpp>

#include "example.hpp"

HIDE(
/// [pair1]
using p = metal::list<int, unsigned>;
/// [pair1]

IS_SAME(metal::is_pair<p>, metal::true_);
)

HIDE(
/// [is_pair]
IS_SAME(metal::is_pair<metal::pair<int, unsigned>>, metal::true_);
IS_SAME(metal::is_pair<metal::list<void, void*>>, metal::true_);
IS_SAME(metal::is_pair<metal::list<void>>, metal::false_);
/// [is_pair]
)

HIDE(
/// [first]
IS_SAME(metal::first<metal::pair<void, void*>>, void);
/// [first]
)

HIDE(
/// [second]
IS_SAME(metal::second<metal::pair<void, void*>>, void*);
/// [second]
)
