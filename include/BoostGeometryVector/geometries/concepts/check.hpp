//          Copyright Jeremy Coulon 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"
#include "BoostGeometryVector/geometries/concepts/vector_concept.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/geometries/concepts/check.hpp>

namespace boost
{
    namespace geometry
    {
        namespace dispatch
        {

            template <typename Geometry>
            struct check<Geometry, vector_tag, true>
                : detail::concept_check::check<concept::ConstVector<Geometry> >
            {};


            template <typename Geometry>
            struct check<Geometry, vector_tag, false>
                : detail::concept_check::check<concept::Vector<Geometry> >
            {};

        } // namespace boost::geometry::dispatch
    } // namespace boost::geometry
} // namespace boost
