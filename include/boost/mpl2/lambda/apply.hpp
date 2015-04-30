// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_APPLY_HPP
#define BOOST_MPL2_LAMBDA_APPLY_HPP

#include <boost/mpl2/lambda/lambda.hpp>
#include <boost/mpl2/lambda/invoke.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename expr, typename... args>
        struct apply :
                invoke<lambda<expr>, args...>
        {};
    }
}

#endif