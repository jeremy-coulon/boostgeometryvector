
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"
#include "BoostGeometryVector/algorithms/detail/convert_vector_to_vector.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/algorithms/convert.hpp>

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
            template
            <
                typename Geometry1, typename Geometry2,
                std::size_t DimensionCount
            >
            struct convert<Geometry1, Geometry2, vector_tag, vector_tag, DimensionCount, false>
                : detail::conversion::vector_to_vector<Geometry1, Geometry2, 0, DimensionCount>
            {};
        }
    }
}
