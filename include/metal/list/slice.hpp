// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_SLICE_HPP
#define METAL_LIST_SLICE_HPP

#include <metal/config.hpp>

#include <metal/list/at.hpp>
#include <metal/list/list.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/number/if.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// TODO
    template<typename seq, typename nums>
    using slice = metal::transform<
        metal::partial<
            metal::lambda<metal::at>,
            metal::if_<metal::is_list<seq>,seq>
        >,
        nums
    >;
}

#endif
