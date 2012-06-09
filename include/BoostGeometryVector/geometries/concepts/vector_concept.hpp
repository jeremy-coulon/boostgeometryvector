
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"
#include "BoostGeometryVector/core/access.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/concept_check.hpp>
#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/coordinate_system.hpp>
#include <boost/geometry/geometries/concepts/point_concept.hpp>

//===========
//==  STD  ==
//===========
#include <cstddef>

namespace boost
{
    namespace geometry
    {
        namespace concept
        {
            /*!
            \brief Vector concept.
            \ingroup concepts

            \par Formal definition:
            The vector concept is defined as following:
            - there must be a specialization of traits::tag defining vector_tag as type
            - there must be a specialization of traits::point_type to define the
              underlying point type (even if it does not consist of points, it should define
              this type, to indicate the points it can work with)
            - there must be a specialization of traits::coordinate_type defining the type
              of its coordinates
            - there must be a specialization of traits::coordinate_system defining its
              coordinate system (cartesian, spherical, etc)
            - there must be a specialization of traits::dimension defining its number
              of dimensions (2, 3, ...) (derive it conveniently
              from boost::mpl::int_&lt;X&gt; for X-D)
            - there must be a specialization of traits::access, per dimension,
              with two functions:
              - \b get to get a coordinate value
              - \b set to set a coordinate value (this one is not checked for ConstVector)
            */
            template <typename Geometry>
            class Vector
            {
            private:

                typedef typename coordinate_type<Geometry>::type ctype;
                typedef typename coordinate_system<Geometry>::type csystem;
                typedef typename tag<Geometry>::type ctag;
                typedef typename point_type<Geometry>::type cpoint_type;

                BOOST_CONCEPT_ASSERT( (concept::Point<cpoint_type>) );

                enum { ccount = dimension<Geometry>::value };

                template <typename P, std::size_t Dimension, std::size_t DimensionCount>
                struct dimension_checker
                {
                    static void apply()
                    {
                        P* p = 0;
                        geometry::set<Dimension>(*p, geometry::get<Dimension>(*p));
                        dimension_checker<P, Dimension+1, DimensionCount>::apply();
                    }
                };


                template <typename P, std::size_t DimensionCount>
                struct dimension_checker<P, DimensionCount, DimensionCount>
                {
                    static void apply() {}
                };

                // Type deduction will fail unless the arguments have the same type.
                template <typename T>
                static void same_type(T const&, T const&) {}

                struct tag_checker
                {
                    static void apply()
                    {
                        ctag        g_tag;
                        vector_tag  v_tag;
                        same_type(g_tag, v_tag);
                    }
                };

            public:

                /// BCCL macro to apply the Vector concept
                BOOST_CONCEPT_USAGE(Vector)
                {
                    dimension_checker<Geometry, 0, ccount>::apply();
                    tag_checker::apply();
                }
            };

            /*!
            \brief vector concept (const version).

            \ingroup const_concepts

            \details The ConstVector concept apply the same as the Vector concept,
            but does not apply write access.

            */
            template <typename Geometry>
            class ConstVector
            {
            private:

                typedef typename coordinate_type<Geometry>::type ctype;
                typedef typename coordinate_system<Geometry>::type csystem;
                typedef typename tag<Geometry>::type ctag;
                typedef typename point_type<Geometry>::type cpoint_type;

                BOOST_CONCEPT_ASSERT( (concept::ConstPoint<cpoint_type>) );

                enum { ccount = dimension<Geometry>::value };

                template <typename P, std::size_t Dimension, std::size_t DimensionCount>
                struct dimension_checker
                {
                    static void apply()
                    {
                        const P* p = 0;
                        ctype coord(geometry::get<Dimension>(*p));
                        boost::ignore_unused_variable_warning(coord);
                        dimension_checker<P, Dimension+1, DimensionCount>::apply();
                    }
                };


                template <typename P, std::size_t DimensionCount>
                struct dimension_checker<P, DimensionCount, DimensionCount>
                {
                    static void apply() {}
                };

                // Type deduction will fail unless the arguments have the same type.
                template <typename T>
                static void same_type(T const&, T const&) {}

                struct tag_checker
                {
                    static void apply()
                    {
                        ctag        g_tag;
                        vector_tag  v_tag;
                        same_type(g_tag, v_tag);
                    }
                };

            public:

                /// BCCL macro to apply the ConstVector concept
                BOOST_CONCEPT_USAGE(ConstVector)
                {
                    dimension_checker<Geometry, 0, ccount>::apply();
                    tag_checker::apply();
                }
            };

        } // namespace concept
    } // namespace geometry
} // namespace boost


