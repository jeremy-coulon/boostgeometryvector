
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
#include <boost/geometry/core/geometry_id.hpp>
#include <boost/mpl/int.hpp>

namespace boost
{
    namespace geometry
    {
        namespace core_dispatch
        {

            template <>
            struct geometry_id<vector_tag> : boost::mpl::int_<42> {};

        } // namespace core_dispatch
    } // namespace geometry
} // namespace boost
