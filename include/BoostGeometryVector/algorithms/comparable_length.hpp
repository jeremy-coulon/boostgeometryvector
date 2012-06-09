
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/strategies/length.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/geometries/concepts/check.hpp>
#include <boost/geometry/core/tag.hpp>
#include <boost/geometry/algorithms/length.hpp>
#include <boost/geometry/strategies/default_length_result.hpp>

namespace boost
{
    namespace geometry
    {

        /*!
        \brief \brief_calc2{comparable length measurement}
        \ingroup length
        \details The free function comparable_length does not necessarily calculate the length,
        but it calculates a length measure such that two lengths are comparable to each other.
        For example: for the Cartesian coordinate system, Pythagoras is used but the square root
        is not taken, which makes it faster and the results of two vector pairs can still be
        compared to each other.
        \tparam Geometry geometry type
        \param geometry \param_geometry
        \return \return_calc{comparable length}
        */
        template <typename Geometry>
        inline typename default_length_result<Geometry>::type comparable_length(
                    Geometry const& geometry)
        {
            concept::check<Geometry const>();

            typedef typename strategy::length::services::comparable_type
                <
                    typename strategy::length::services::default_strategy
                            <typename tag<Geometry>::type, Geometry>::type
                >::type strategy_type;

            return length(geometry, strategy_type());
        }

    } // namespace geometry
} // namespace boost
