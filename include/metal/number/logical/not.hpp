// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_NOT_HPP
#define METAL_NUMBER_LOGICAL_NOT_HPP

#include <metal/number/number.hpp>
#include <metal/optional/extract.hpp>

namespace metal
{
    /// \ingroup logical
    /// \brief ...
    template<typename num>
    struct not_
    {};

    /// \ingroup logical
    /// \brief Eager adaptor for \ref not_.
    template<typename num>
    using not_t = extract<not_<num>>;

    template<typename t, t v>
    struct not_<number<t, v>> :
            boolean<v ? false : true>
    {};
}

#endif