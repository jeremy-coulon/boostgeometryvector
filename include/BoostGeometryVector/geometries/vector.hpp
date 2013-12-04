//          Copyright Jeremy Coulon 2012-2013.
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
#include <boost/geometry/core/tag.hpp>
#include <boost/geometry/core/access.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_system.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/point_type.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/static_assert.hpp>
#include <boost/mpl/int.hpp>

//===========
//==  STD  ==
//===========
#include <cstddef>

namespace boost
{
    namespace geometry
    {
        namespace model
        {

            /*!
            \brief Basic vector class, having coordinates defined in a neutral way
            \details Defines a neutral vector class, fulfilling the Vector Concept.
                Library users can use this vector class, or use their own vector classes.
                This vector class is used in most of the samples and tests of Boost.Geometry
                This vector class is used occasionally within the library, where a temporary
                point class is necessary.
            \ingroup geometries
            \tparam CoordinateType \tparam_numeric
            \tparam DimensionCount number of coordinates, usually 2 or 3
            \tparam CoordinateSystem coordinate system, for example cs::cartesian
            */
            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            class vector
            {
            public:

                /// @brief Default constructor, no initialization
                inline vector()
                {}

                /// @brief Constructor to set one, two or three values
                inline vector(CoordinateType const& v0, CoordinateType const& v1 = 0, CoordinateType const& v2 = 0)
                {
                    if (DimensionCount >= 1) m_values[0] = v0;
                    if (DimensionCount >= 2) m_values[1] = v1;
                    if (DimensionCount >= 3) m_values[2] = v2;
                }

                /// @brief Get a coordinate
                /// @tparam K coordinate to get
                /// @return the coordinate
                template <std::size_t K>
                inline CoordinateType const& get() const
                {
                    BOOST_STATIC_ASSERT(K < DimensionCount);
                    return m_values[K];
                }

                /// @brief Set a coordinate
                /// @tparam K coordinate to set
                /// @param value value to set
                template <std::size_t K>
                inline void set(CoordinateType const& value)
                {
                    BOOST_STATIC_ASSERT(K < DimensionCount);
                    m_values[K] = value;
                }

            private:

                CoordinateType m_values[DimensionCount];
            };

        } // namespace model

#ifndef DOXYGEN_NO_TRAITS_SPECIALIZATIONS
        namespace traits
        {

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            struct tag< model::vector<CoordinateType, DimensionCount, CoordinateSystem> >
            {
                typedef vector_tag type;
            };

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            struct point_type< model::vector<CoordinateType, DimensionCount, CoordinateSystem> >
            {
                typedef model::point<CoordinateType, DimensionCount, CoordinateSystem> type;
            };

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            struct coordinate_type<model::vector<CoordinateType, DimensionCount, CoordinateSystem> >
            {
                typedef CoordinateType type;
            };

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            struct coordinate_system<model::vector<CoordinateType, DimensionCount, CoordinateSystem> >
            {
                typedef CoordinateSystem type;
            };

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem
            >
            struct dimension<model::vector<CoordinateType, DimensionCount, CoordinateSystem> >
                : boost::mpl::int_<DimensionCount>
            {};

            template
            <
                typename CoordinateType,
                std::size_t DimensionCount,
                typename CoordinateSystem,
                std::size_t Dimension
            >
            struct access<model::vector<CoordinateType, DimensionCount, CoordinateSystem>, Dimension>
            {
                static inline CoordinateType get(
                    model::vector<CoordinateType, DimensionCount, CoordinateSystem> const& p)
                {
                    return p.template get<Dimension>();
                }

                static inline void set(
                    model::vector<CoordinateType, DimensionCount, CoordinateSystem>& p,
                    CoordinateType const& value)
                {
                    p.template set<Dimension>(value);
                }
            };

        } // namespace traits
#endif
    } // namespace geometry
} // namespace boost
