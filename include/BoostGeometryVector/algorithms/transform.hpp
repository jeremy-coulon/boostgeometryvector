
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
#include <boost/geometry/algorithms/transform.hpp>

namespace boost
{
    namespace geometry
    {
        namespace detail
        {
            namespace transform
            {

                template <typename Vector1, typename Vector2, typename Strategy>
                struct transform_vector
                {
                    static inline bool apply(Vector1 const& v1, Vector2& v2,
                                Strategy const& strategy)
                    {
                        return strategy.apply(v1, v2);
                    }
                };

            } // namespace transform
        } // namespace detail

        namespace dispatch
        {

            template <typename Vector1, typename Vector2, typename Strategy>
            struct transform<vector_tag, vector_tag, Vector1, Vector2, Strategy>
                : detail::transform::transform_vector<Vector1, Vector2, Strategy>
            {
            };

        } // namespace dispatch
    } // namespace geometry
} // namespace boost
