//          Copyright Jeremy Coulon 2012-2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//=============
//==  Boost  ==
//=============
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/access.hpp>
#include <boost/numeric/conversion/cast.hpp>

//===========
//==  STD  ==
//===========
#include <cstddef>

namespace boost
{
    namespace geometry
    {
#ifndef DOXYGEN_NO_DETAIL
        namespace detail
        {
            namespace conversion
            {

                template <typename Source, typename Destination, std::size_t Dimension, std::size_t DimensionCount>
                struct vector_to_vector
                {
                    static inline void apply(Source const& source, Destination& destination)
                    {
                        typedef typename coordinate_type<Destination>::type coordinate_type;

                        set<Dimension>(destination, boost::numeric_cast<coordinate_type>(get<Dimension>(source)));
                        vector_to_vector<Source, Destination, Dimension + 1, DimensionCount>::apply(source, destination);
                    }
                };

                template <typename Source, typename Destination, std::size_t DimensionCount>
                struct vector_to_vector<Source, Destination, DimensionCount, DimensionCount>
                {
                    static inline void apply(Source const& , Destination& )
                    {}
                };

                template <typename Source, typename Destination>
                inline void convert_vector_to_vector(Source const& source, Destination& destination)
                {
                    vector_to_vector<Source, Destination, 0, dimension<Destination>::value>::apply(source, destination);
                }

            } // namespace conversion
        } // namespace detail
#endif
    } // namespace geometry
} // namespace boost
