// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_NUMBER_LESS_HPP
#define METAL_NUMBER_LESS_HPP

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _less;
    }

    /// \ingroup number
    /// Checks whether a \number is less than another.
    ///
    /// ### Usage
    /// For any \numbers `num_1` and `num_2`
    /// \code
    ///     using result = metal::less<num_1, num_2>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     \code
    ///         using result = metal::number<(num_1{} < num_2{})>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp less
    ///
    /// ### See Also
    /// \see number, greater
    template<typename x, typename y>
    using less = typename detail::_less<x, y>::type;
}

#include <metal/number/number.hpp>

namespace metal
{
    namespace detail
    {
        template<typename x, typename y>
        struct _less
        {};

        template<int_ x, int_ y>
        struct _less<number<x>, number<y>> :
            number<(x < y)>
        {};
    }
}

#endif