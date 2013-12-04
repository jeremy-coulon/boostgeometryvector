//          Copyright Jeremy Coulon 2012-2013.
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
#include <boost/geometry/util/for_each_coordinate.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>
#include <boost/geometry/algorithms/detail/assign_values.hpp>
#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/concept_check.hpp>
#include <boost/numeric/conversion/cast.hpp>

namespace boost
{
    namespace geometry
    {
#ifndef DOXYGEN_NO_DETAIL
        namespace detail
        {
            namespace assign
            {

                template <typename Vector>
                struct assign_zero_vector
                {
                    static inline void apply(Vector& vector)
                    {
                        BOOST_CONCEPT_ASSERT( (concept::Vector<Vector>) );

                        typedef typename detail::coordinates_scanner
                            <
                                Vector, 0, dimension<Vector>::type::value, false
                            > scanner;

                        scanner::apply(vector, detail::value_assignment<typename coordinate_type<Vector>::type>(0));
                    }
                };

            } // namespace assign
        } // namespace detail
#endif

#ifndef DOXYGEN_NO_DISPATCH
        namespace dispatch
        {

            template <typename Vector>
            struct assign<vector_tag, Vector, 2>
            {
                typedef typename coordinate_type<Vector>::type coordinate_type;

                template <typename T>
                static inline void apply(Vector& vector, T const& c1, T const& c2)
                {
                    set<0>(vector, boost::numeric_cast<coordinate_type>(c1));
                    set<1>(vector, boost::numeric_cast<coordinate_type>(c2));
                }
            };

            template <typename Vector>
            struct assign<vector_tag, Vector, 3>
            {
                typedef typename coordinate_type<Vector>::type coordinate_type;

                template <typename T>
                static inline void apply(Vector& vector, T const& c1, T const& c2, T const& c3)
                {
                    set<0>(vector, boost::numeric_cast<coordinate_type>(c1));
                    set<1>(vector, boost::numeric_cast<coordinate_type>(c2));
                    set<2>(vector, boost::numeric_cast<coordinate_type>(c3));
                }
            };

            template <typename Vector>
            struct assign<vector_tag, Vector, 4>
            {
                typedef typename coordinate_type<Vector>::type coordinate_type;

                template <typename T>
                static inline void apply(Vector& vector, T const& c1, T const& c2, T const& c3, T const& c4)
                {
                    set<0>(vector, boost::numeric_cast<coordinate_type>(c1));
                    set<1>(vector, boost::numeric_cast<coordinate_type>(c2));
                    set<2>(vector, boost::numeric_cast<coordinate_type>(c3));
                    set<3>(vector, boost::numeric_cast<coordinate_type>(c4));
                }
            };

            template <typename Vector>
            struct assign_zero<vector_tag, Vector>
                : detail::assign::assign_zero_vector<Vector>
            {};

        } // namespace dispatch
#endif
    } // namespace geometry
} // namespace boost
