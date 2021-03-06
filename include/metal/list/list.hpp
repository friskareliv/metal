// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_LIST_HPP
#define METAL_LIST_LIST_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_list;

        template<typename... vals>
        struct list {};
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether some \value is a \list.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_list<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is a \list, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp is_list
    ///
    /// ### See Also
    /// \see list, is_value, is_number, is_lambda, is_pair, is_map
    template<typename val>
    using is_list = typename detail::_is_list<val>::type;

    /// \ingroup list
    ///
    /// ### Description
    /// Constructs a \list out of a sequence of \values.
    ///
    /// ### Usage
    /// For any \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::pair<val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    ///
    /// ### See Also
    /// \see is_list
    template<typename... vals>
    using list = detail::list<vals...>;
}

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_list :
            false_
        {};

        template<typename... vals>
        struct _is_list<list<vals...>> :
            true_
        {};
    }
    /// \endcond
}

#endif
