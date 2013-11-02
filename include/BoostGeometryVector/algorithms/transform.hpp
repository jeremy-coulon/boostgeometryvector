
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
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/util/select_coordinate_type.hpp>
#include <boost/geometry/algorithms/transform.hpp>
#include <boost/geometry/algorithms/assign.hpp>
#include <boost/geometry/strategies/transform/matrix_transformers.hpp>
#include <boost/geometry/strategies/transform/inverse_transformer.hpp>
#include <boost/numeric/ublas/matrix.hpp>

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
            namespace transform
            {

                template <typename Vector1, typename Vector2,
                          std::size_t Dimension1, std::size_t Dimension2,
                          typename Strategy>
                struct transform_vector
                {
                    // Not implemented if Vector1 and Vector2 don't have the same dimension
                };

                template <typename Vector1, typename Vector2,
                          std::size_t Dim,
                          typename Strategy>
                struct transform_vector<Vector1, Vector2, Dim, Dim, Strategy>
                {
                    // General case : apply the given strategy
                    static inline bool apply(Vector1 const& v1, Vector2& v2,
                                Strategy const& strategy)
                    {
                        return strategy.apply(v1, v2);
                    }
                };

                // Template partial specialization for translate_transformer
                template <typename Vector1, typename Vector2, std::size_t Dim>
                struct transform_vector< Vector1, Vector2, Dim, Dim, strategy::transform::translate_transformer<Vector1, Vector2> >
                {
                    typedef typename strategy::transform::translate_transformer<Vector1, Vector2> Strategy;

                    static inline bool apply(Vector1 const& v1, Vector2& v2,
                                Strategy const& /*strategy*/)
                    {
                        // Don't translate a vector
                        geometry::assign(v2, v1);
                        return true;
                    }
                };

                // Template partial specialization for 2D ublas_transformer
                template <typename Vector1, typename Vector2>
                struct transform_vector< Vector1, Vector2, 2, 2, strategy::transform::ublas_transformer<Vector1, Vector2, 2, 2> >
                {
                    typedef typename strategy::transform::ublas_transformer<Vector1, Vector2, 2, 2> Strategy;
                    typedef typename select_coordinate_type<Vector1, Vector2>::type coordinate_type;
                    typedef boost::numeric::ublas::matrix<coordinate_type> matrix_type;

                    static inline bool apply(Vector1 const& v1, Vector2& v2,
                                Strategy const& strategy)
                    {
                        // This is a 3x3 matrix
                        const matrix_type& matrix = strategy.matrix();

                        coordinate_type const& c1 = get<0>(v1);
                        coordinate_type const& c2 = get<1>(v1);

                        // Don't translate a vector => we don't use the last column of the matrix
                        coordinate_type p2x = c1 * matrix(0,0) + c2 * matrix(0,1);
                        coordinate_type p2y = c1 * matrix(1,0) + c2 * matrix(1,1);

                        typedef typename geometry::coordinate_type<Vector2>::type ct2;
                        set<0>(v2, boost::numeric_cast<ct2>(p2x));
                        set<1>(v2, boost::numeric_cast<ct2>(p2y));

                        return true;
                    }
                };

                // Template partial specialization for 3D ublas_transformer
                template <typename Vector1, typename Vector2>
                struct transform_vector< Vector1, Vector2, 3, 3, strategy::transform::ublas_transformer<Vector1, Vector2, 3, 3> >
                {
                    typedef typename strategy::transform::ublas_transformer<Vector1, Vector2, 3, 3> Strategy;
                    typedef typename select_coordinate_type<Vector1, Vector2>::type coordinate_type;
                    typedef boost::numeric::ublas::matrix<coordinate_type> matrix_type;

                    static inline bool apply(Vector1 const& v1, Vector2& v2,
                                Strategy const& strategy)
                    {
                        // This is a 4x4 matrix
                        const matrix_type& matrix = strategy.matrix();

                        coordinate_type const& c1 = get<0>(v1);
                        coordinate_type const& c2 = get<1>(v1);
                        coordinate_type const& c3 = get<2>(v1);

                        // Don't translate a vector => we don't use the last column of the matrix
                        coordinate_type p2x = c1 * matrix(0,0) + c2 * matrix(0,1) + c3 * matrix(0,2);
                        coordinate_type p2y = c1 * matrix(1,0) + c2 * matrix(1,1) + c3 * matrix(1,2);
                        coordinate_type p2z = c1 * matrix(2,0) + c2 * matrix(2,1) + c3 * matrix(2,2);

                        typedef typename geometry::coordinate_type<Vector2>::type ct2;
                        set<0>(v2, boost::numeric_cast<ct2>(p2x));
                        set<1>(v2, boost::numeric_cast<ct2>(p2y));
                        set<2>(v2, boost::numeric_cast<ct2>(p2z));

                        return true;
                    }
                };

                // Template partial specialization for inverse_transformer
                template <typename Vector1, typename Vector2, std::size_t Dim>
                struct transform_vector< Vector1, Vector2, Dim, Dim, strategy::transform::inverse_transformer<Vector1, Vector2> >
                        : transform_vector< Vector1, Vector2, Dim, Dim, strategy::transform::ublas_transformer<Vector1, Vector2, Dim, Dim> >
                {
                    // Apply will call the correct template specialization for ublas_transformer
                };

            } // namespace transform
        } // namespace detail

        namespace dispatch
        {

            template <typename Vector1, typename Vector2>
            struct transform<Vector1, Vector2, vector_tag, vector_tag>
            {
                template <typename Strategy>
                static inline bool apply(Vector1 const& v1, Vector2& v2, Strategy const& strategy)
                {
                    return detail::transform::transform_vector<
                            Vector1, Vector2,
                            geometry::dimension<Vector1>::type::value,
                            geometry::dimension<Vector2>::type::value,
                            Strategy
                            >::apply(v1, v2, strategy);
                }
            };

        } // namespace dispatch
    } // namespace geometry
} // namespace boost
