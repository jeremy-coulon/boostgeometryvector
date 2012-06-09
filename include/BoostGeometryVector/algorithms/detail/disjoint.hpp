
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//=============
//==  Boost  ==
//=============
#include <boost/geometry/util/math.hpp>
#include <boost/geometry/core/access.hpp>

//===========
//==  STD  ==
//===========
#include <cstddef>

namespace boost
{
    namespace geometry
    {
        namespace detail
        {
            namespace disjoint
            {
                template
                <
                    typename Vector1, typename Vector2,
                    std::size_t Dimension, std::size_t DimensionCount
                >
                struct vector_vector
                {
                    static inline bool apply(Vector1 const& v1, Vector2 const& v2)
                    {
                        if (! geometry::math::equals(get<Dimension>(v1), get<Dimension>(v2)))
                        {
                            return true;
                        }
                        return vector_vector
                            <
                                Vector1, Vector2,
                                Dimension + 1, DimensionCount
                            >::apply(v1, v2);
                    }
                };


                template <typename Vector1, typename Vector2, std::size_t DimensionCount>
                struct vector_vector<Vector1, Vector2, DimensionCount, DimensionCount>
                {
                    static inline bool apply(Vector1 const& , Vector2 const& )
                    {
                        return false;
                    }
                };
            }
        }
    }
}
