// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_LAMBDA_HPP
#define METAL_LAMBDA_LAMBDA_HPP

#include <metal/config.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_lambda;

        template<template<typename...> class expr>
        struct lambda {};
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    ///
    /// ### See Also
    /// \see lambda, is_value, is_number, is_pair, is_list, is_map
    template<typename val>
    using is_lambda = typename detail::_is_lambda<val>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<template<typename...> class expr>
    using lambda = detail::lambda<expr>;
}

#include <metal/number/number.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename val>
        struct _is_lambda :
            false_
        {};

        template<template<typename...> class expr>
        struct _is_lambda<lambda<expr>> :
            true_
        {};
    }
    /// \endcond
}

#endif

