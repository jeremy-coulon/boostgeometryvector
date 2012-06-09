
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//=============
//==  Boost  ==
//=============
#include <boost/geometry/core/tags.hpp>

namespace boost
{
    namespace geometry
    {
        // Tags defining tag hierarchy

        /// For vector-like types (vector)
        struct vectorlike_tag {};

        // Tags defining geometry types

        /// Vector identifying tag
        struct vector_tag : single_tag, vectorlike_tag {};

    } // namespace boost::geometry
} // namespace boost
