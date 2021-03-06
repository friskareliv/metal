// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

#include <metal/config.hpp>

#include <metal/number/not.hpp>
#include <metal/number/number.hpp>
#include <metal/value/value.hpp>
#include <metal/value/same.hpp>

#include <type_traits>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename seq, typename = true_>
        struct _invoke_impl;

        template<typename lbd, typename... args>
        struct _invoke;
    }
    /// \endcond

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<typename lbd, typename... args>
    using invoke = typename detail::_invoke<lbd, args...>::type;

    /// \ingroup lambda
    ///
    /// ### Description
    /// ...
    template<typename lbd, typename... args>
    using is_invocable = same<
        typename std::is_base_of<
            value<>,
            detail::_invoke<lbd, args...>
        >::type,
        std::false_type
    >;
}

#include <metal/lambda/lambda.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    /// \cond
    namespace detail
    {
        template<typename lbd, typename seq, typename>
        struct _invoke_impl :
            value<>
        {};

        template<
            template<typename...> class expr,
            typename head, typename... tail
        >
        struct _invoke_impl<lambda<expr>, list<head, tail...>,
            is_value<expr<head, tail...>>
        > :
            value<expr<head, tail...>>
        {};

        template<template<typename...> class expr>
        struct _invoke_impl<lambda<expr>, list<>,
            is_value<expr<>>
        > :
            value<expr<>>
        {};

        template<typename lbd, typename... args>
        struct _invoke :
            _invoke_impl<lbd, list<args...>>
        {};
    }
    /// \endcond
}

#endif
