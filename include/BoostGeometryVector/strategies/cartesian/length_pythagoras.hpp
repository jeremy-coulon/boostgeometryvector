
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/geometries/concepts/vector_concept.hpp"
#include "BoostGeometryVector/strategies/tags.hpp"
#include "BoostGeometryVector/strategies/length.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/numeric/conversion/cast.hpp>
#include <boost/geometry/util/calculation_type.hpp>
#include <boost/geometry/geometries/concepts/check.hpp>

namespace boost
{
    namespace geometry
    {
        namespace strategy
        {
            namespace length
            {
                namespace detail
                {

                    template <typename Geometry1, size_t I, typename T>
                    struct compute_pythagoras
                    {
                        static inline T apply(Geometry1 const& g1)
                        {
                            T const d = boost::numeric_cast<T>(get<I-1>(g1));
                            return d * d + compute_pythagoras<Geometry1, I-1, T>::apply(g1);
                        }
                    };

                    template <typename Geometry1, typename T>
                    struct compute_pythagoras<Geometry1, 0, T>
                    {
                        static inline T apply(Geometry1 const&)
                        {
                            return boost::numeric_cast<T>(0);
                        }
                    };

                } // namespace detail

                namespace comparable
                {

                    /*!
                    \brief Strategy to calculate comparable distance between two vectors
                    \ingroup strategies
                    \tparam Vector \tparam_vector
                    \tparam CalculationType \tparam_calculation
                    */
                    template
                    <
                        typename Vector,
                        typename CalculationType = void
                    >
                    class pythagoras
                    {
                    public :

                        typedef typename util::calculation_type::geometric::unary
                                <
                                    Vector,
                                    CalculationType
                                >::type calculation_type;

                        static inline calculation_type apply(Vector const& v)
                        {
                            BOOST_CONCEPT_ASSERT( (concept::ConstVector<Vector>) );

                            // Calculate distance using Pythagoras

                            return detail::compute_pythagoras
                                <
                                    Vector,
                                    dimension<Vector>::value,
                                    calculation_type
                                >::apply(v);
                        }
                    };

                } // namespace comparable

                /*!
                \brief Strategy to calculate the length of vector
                \ingroup strategies
                \tparam Vector \tparam_vector
                \tparam CalculationType \tparam_calculation
                */
                template
                <
                    typename Vector,
                    typename CalculationType = void
                >
                class pythagoras
                {
                    typedef comparable::pythagoras<Vector, CalculationType> comparable_type;
                public :
                    typedef typename util::calculation_type::geometric::unary
                            <
                                Vector,
                                CalculationType,
                                double,
                                double // promote integer to double
                            >::type calculation_type;

                    /*!
                    \brief applies the length calculation using pythagoras
                    \return the calculated length (including taking the square root)
                    \param v vector
                    */
                    static inline calculation_type apply(Vector const& v)
                    {
                        calculation_type const t = comparable_type::apply(v);
                        return sqrt(t);
                    }
                };

                namespace services
                {

                    template <typename Vector, typename CalculationType>
                    struct tag<pythagoras<Vector, CalculationType> >
                    {
                        typedef strategy_tag_length_vector type;
                    };


                    template <typename Vector, typename CalculationType>
                    struct return_type<pythagoras<Vector, CalculationType> >
                    {
                        typedef typename pythagoras<Vector, CalculationType>::calculation_type type;
                    };


                    template
                    <
                        typename Vector1,
                        typename CalculationType,
                        typename V1
                    >
                    struct similar_type<pythagoras<Vector1, CalculationType>, V1>
                    {
                        typedef pythagoras<V1, CalculationType> type;
                    };


                    template
                    <
                        typename Vector1,
                        typename CalculationType,
                        typename V1
                    >
                    struct get_similar<pythagoras<Vector1, CalculationType>, V1>
                    {
                        static inline typename similar_type
                            <
                                pythagoras<Vector1, CalculationType>, V1
                            >::type apply(pythagoras<Vector1, CalculationType> const& )
                        {
                            return pythagoras<V1, CalculationType>();
                        }
                    };


                    template <typename Vector1, typename CalculationType>
                    struct comparable_type<pythagoras<Vector1, CalculationType> >
                    {
                        typedef comparable::pythagoras<Vector1, CalculationType> type;
                    };


                    template <typename Vector1, typename CalculationType>
                    struct get_comparable<pythagoras<Vector1, CalculationType> >
                    {
                        typedef comparable::pythagoras<Vector1, CalculationType> comparable_type;
                    public :
                        static inline comparable_type apply(pythagoras<Vector1, CalculationType> const& )
                        {
                            return comparable_type();
                        }
                    };


                    template <typename Vector1, typename CalculationType>
                    struct result_from_length<pythagoras<Vector1, CalculationType> >
                    {
                    private :
                        typedef typename return_type<pythagoras<Vector1, CalculationType> >::type return_type;
                    public :
                        template <typename T>
                        static inline return_type apply(pythagoras<Vector1, CalculationType> const& , T const& value)
                        {
                            return return_type(value);
                        }
                    };


                    // Specializations for comparable::pythagoras
                    template <typename Vector1, typename CalculationType>
                    struct tag<comparable::pythagoras<Vector1, CalculationType> >
                    {
                        typedef strategy_tag_length_vector type;
                    };


                    template <typename Vector1, typename CalculationType>
                    struct return_type<comparable::pythagoras<Vector1, CalculationType> >
                    {
                        typedef typename comparable::pythagoras<Vector1, CalculationType>::calculation_type type;
                    };

                    template
                    <
                        typename Vector1,
                        typename CalculationType,
                        typename V1
                    >
                    struct similar_type<comparable::pythagoras<Vector1, CalculationType>, V1>
                    {
                        typedef comparable::pythagoras<V1, CalculationType> type;
                    };


                    template
                    <
                        typename Vector1,
                        typename CalculationType,
                        typename V1
                    >
                    struct get_similar<comparable::pythagoras<Vector1, CalculationType>, V1>
                    {
                        static inline typename similar_type
                            <
                                comparable::pythagoras<Vector1, CalculationType>, V1
                            >::type apply(comparable::pythagoras<Vector1, CalculationType> const& )
                        {
                            return comparable::pythagoras<V1, CalculationType>();
                        }
                    };


                    template <typename Vector1, typename CalculationType>
                    struct comparable_type<comparable::pythagoras<Vector1, CalculationType> >
                    {
                        typedef comparable::pythagoras<Vector1, CalculationType> type;
                    };


                    template <typename Vector1, typename CalculationType>
                    struct get_comparable<comparable::pythagoras<Vector1, CalculationType> >
                    {
                        typedef comparable::pythagoras<Vector1, CalculationType> comparable_type;
                    public :
                        static inline comparable_type apply(comparable::pythagoras<Vector1, CalculationType> const& )
                        {
                            return comparable_type();
                        }
                    };


                    template <typename Vector1, typename CalculationType>
                    struct result_from_length<comparable::pythagoras<Vector1, CalculationType> >
                    {
                    private :
                        typedef typename return_type<comparable::pythagoras<Vector1, CalculationType> >::type return_type;
                    public :
                        template <typename T>
                        static inline return_type apply(comparable::pythagoras<Vector1, CalculationType> const& , T const& value)
                        {
                            return_type const v = value;
                            return v * v;
                        }
                    };

                    template <typename Geometry1>
                    struct default_strategy<vector_tag, Geometry1, cartesian_tag, void>
                    {
                        typedef pythagoras<Geometry1> type;
                    };

                } // namespace services
            } // namespace length
        } // namespace strategy
    } // namespace geometry
} // namespace boost
