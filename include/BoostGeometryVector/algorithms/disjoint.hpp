
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"
#include "BoostGeometryVector/algorithms/detail/disjoint.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/algorithms/disjoint.hpp>

//===========
//==  STD  ==
//===========
#include <cstddef>

namespace boost
{
    namespace geometry
    {
        namespace dispatch
        {

            template <typename Vector1, typename Vector2, std::size_t DimensionCount, bool Reverse>
            struct disjoint<Vector1, Vector2, DimensionCount, vector_tag, vector_tag, Reverse>
                : detail::disjoint::vector_vector<Vector1, Vector2, 0, DimensionCount>
            {};

        } // namespace dispatch
    } // namespace geometry
} // namespace boost
