
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
#include <boost/geometry/core/closure.hpp>

namespace boost
{
    namespace geometry
    {
        namespace core_dispatch
        {

            template <typename Vector>
            struct closure<vector_tag, Vector> : public core_detail::closure::closed {};

        } // namespace core_dispatch
    } // namespace geometry
} // namespace boost
