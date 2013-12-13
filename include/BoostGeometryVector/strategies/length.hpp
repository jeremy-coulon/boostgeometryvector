//          Copyright Jeremy Coulon 2012-2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//=============
//==  Boost  ==
//=============
#include <boost/mpl/assert.hpp>
#include <boost/geometry/core/cs.hpp>

namespace boost
{
    namespace geometry
    {
        namespace strategy
        {
            namespace length
            {
                namespace services
                {

                    template <typename Strategy> struct tag {};
                    template <typename Strategy> struct return_type
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_STRATEGY, (types<Strategy>)
                        );
#endif
                    };


                    /*!
                    \brief Metafunction delivering a similar strategy with other input geometry types
                    */
                    template
                    <
                            typename Strategy,
                            typename Geometry
                            >
                    struct similar_type
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_STRATEGY, (types<Strategy, Geometry>)
                        );
#endif
                    };

                    template
                    <
                            typename Strategy,
                            typename Geometry
                            >
                    struct get_similar
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_STRATEGY, (types<Strategy, Geometry>)
                        );
#endif
                    };

                    template <typename Strategy> struct comparable_type
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_STRATEGY, (types<Strategy>)
                        );
#endif
                    };

                    template <typename Strategy> struct get_comparable
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_STRATEGY, (types<Strategy>)
                        );
#endif
                    };

                    template <typename Strategy> struct result_from_length {};


                    // Default strategy


                    /*!
                    \brief Traits class binding a default strategy for length
                        to one coordinate system
                    \ingroup length
                    \tparam GeometryTag tag (vector/segment) for which this strategy is the default
                    \tparam Geometry geometry-type
                    \tparam CsTag1 tag of coordinate system of geometry type
                    */
                    template
                    <
                            typename GeometryTag,
                            typename Geometry,
                            typename CsTag1 = typename cs_tag<Geometry>::type,
                            typename UnderlyingStrategy = void
                            >
                    struct default_strategy
                    {
#ifndef DOXYGEN_NO_IMPL
                        BOOST_MPL_ASSERT_MSG
                        (
                            false, NOT_IMPLEMENTED_FOR_THIS_GEOMETRY_TYPE, (types<Geometry, CsTag1>)
                        );
#endif
                    };

                } // namespace services
            } // namespace length
        } // namespace strategy
    } // namespace geometry
} // namespace boost
