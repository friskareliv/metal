// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_EVAL_HPP
#define METAL_OPTIONAL_EVAL_HPP

#include <metal/optional/optional.hpp>

namespace metal
{
    /// \ingroup optional
    /// \brief ...
    template<typename opt, typename fallback = detail::nil>
    using eval = typename optional<opt, fallback>::type;
}

#endif