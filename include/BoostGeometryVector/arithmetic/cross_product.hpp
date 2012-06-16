
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/geometries/concepts/vector_concept.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/concept_check.hpp>

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
            template <typename V, std::size_t Dim>
            struct cross_product
            {};

            template <typename V>
            struct cross_product<V, 3>
            {
                static void apply(V const& a, V const& b, V & result)
                {
                    set<0>(result, get<1>(a) * get<2>(b) - get<2>(a) * get<1>(b));
                    set<1>(result, get<2>(a) * get<0>(b) - get<0>(a) * get<2>(b));
                    set<2>(result, get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b));
                }
            };
        } // namespace detail

        /*!
            \brief Computes the cross product (or vector product) of 2 3D vectors.
            \ingroup arithmetic
            \param v1 first vector
            \param v2 second vector
            \param result cross product
         */
        template <typename V>
        inline void cross_product(
                V const& v1, V const& v2, V & result)
        {
            BOOST_CONCEPT_ASSERT( (concept::Vector<V>) );

            detail::cross_product<
                    V,
                    dimension<V>::value
                    >::apply(v1, v2, result);
        }

    } // namespace geometry
} // namespace boost
