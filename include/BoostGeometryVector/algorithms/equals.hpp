
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
#include <boost/geometry/algorithms/equals.hpp>
#include <boost/geometry/algorithms/detail/not.hpp>

namespace boost
{
    namespace geometry
    {
        namespace dispatch
        {

            template <typename P1, typename P2, std::size_t DimensionCount, bool Reverse>
            struct equals<P1, P2, vector_tag, vector_tag, DimensionCount, Reverse>
                : geometry::detail::not_
                    <
                        P1,
                        P2,
                        detail::disjoint::vector_vector<P1, P2, 0, DimensionCount>
                    >
            {};

        } // namespace dispatch
    } // namespace geometry
} // namespace boost
