
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/core/access.hpp>

namespace boost
{
    namespace geometry
    {
        namespace core_dispatch
        {
            template <typename Vector, typename CoordinateType, std::size_t Dimension>
            struct access<vector_tag, Vector, CoordinateType, Dimension>
            {
                static inline CoordinateType get(Vector const& v)
                {
                    return traits::access<Vector, Dimension>::get(v);
                }
                static inline void set(Vector& v, CoordinateType const& value)
                {
                    traits::access<Vector, Dimension>::set(v, value);
                }
            };

        } // namespace core_dispatch
    } // namespace geometry
} // namespace boost

