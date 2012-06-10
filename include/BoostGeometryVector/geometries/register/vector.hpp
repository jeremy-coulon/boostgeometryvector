
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
#include <boost/geometry/core/tag.hpp>
#include <boost/geometry/core/point_type.hpp>
#include <boost/geometry/core/coordinate_dimension.hpp>
#include <boost/geometry/core/coordinate_type.hpp>
#include <boost/geometry/core/coordinate_system.hpp>
#include <boost/mpl/int.hpp>

// Starting point, specialize basic traits necessary to register a vector
#define BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, Dim, CoordinateType, CoordinateSystem) \
    template<typename P> struct tag< Vector<P> > { typedef vector_tag type; }; \
    template<typename P> struct point_type< Vector<P> > { typedef P type; }; \
    template<typename P> struct dimension< Vector<P> > : boost::mpl::int_<Dim> {}; \
    template<typename P> struct coordinate_type< Vector<P> > { typedef CoordinateType type; }; \
    template<typename P> struct coordinate_system< Vector<P> > { typedef CoordinateSystem type; };

// Specialize access class per dimension
#define BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, Dim, CoordinateType, Get, Set) \
    template<typename P> struct access<Vector<P>, Dim> \
    { \
        static inline CoordinateType get(Vector<P> const& v) { return v. Get; } \
        static inline void set(Vector<P>& v, CoordinateType const& value) { v. Set = value; } \
    };

// Const version
#define BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, Dim, CoordinateType, Get) \
    template<typename P> struct access<Vector<P>, Dim> \
    { \
        static inline CoordinateType get(Vector<P> const& v) { return v. Get; } \
    };

// Getter/setter version
#define BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, Dim, CoordinateType, Get, Set) \
    template<typename P> struct access<Vector<P>, Dim> \
    { \
        static inline CoordinateType get(Vector<P> const& v) \
        { return  v. Get (); } \
        static inline void set(Vector<P>& v, CoordinateType const& value) \
        { v. Set ( value ); } \
    };

/*!
\brief \brief_macro{2D vector type}
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_2D, two-dimensional vector type}
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Field0 \param_macro_member{\macro_x}
\param Field1 \param_macro_member{\macro_y}

\qbk{[include reference/geometries/register/point.qbk]}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_2D(Vector, CoordinateType, CoordinateSystem, Field0, Field1) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 2, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, 0, CoordinateType, Field0, Field0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, 1, CoordinateType, Field1, Field1) \
}}}

/*!
\brief \brief_macro{3D vector type}
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_3D, three-dimensional vector type}
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Field0 \param_macro_member{\macro_x}
\param Field1 \param_macro_member{\macro_y}
\param Field2 \param_macro_member{\macro_z}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_3D(Vector, CoordinateType, CoordinateSystem, Field0, Field1, Field2) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 3, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, 0, CoordinateType, Field0, Field0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, 1, CoordinateType, Field1, Field1) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS(Vector, 2, CoordinateType, Field2, Field2) \
}}}

/*!
\brief \brief_macro{2D vector type} \brief_macro_const
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_2D_CONST, two-dimensional vector type}. \details_macro_const
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Field0 \param_macro_member{\macro_x}
\param Field1 \param_macro_member{\macro_y}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_2D_CONST(Vector, CoordinateType, CoordinateSystem, Field0, Field1) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 2, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, 0, CoordinateType, Field0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, 1, CoordinateType, Field1) \
}}}

/*!
\brief \brief_macro{3D vector type} \brief_macro_const
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_3D_CONST, three-dimensional vector type}. \details_macro_const
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Field0 \param_macro_member{\macro_x}
\param Field1 \param_macro_member{\macro_y}
\param Field2 \param_macro_member{\macro_z}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_3D_CONST(Vector, CoordinateType, CoordinateSystem, Field0, Field1, Field2) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 3, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, 0, CoordinateType, Field0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, 1, CoordinateType, Field1) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_CONST(Vector, 2, CoordinateType, Field2) \
}}}

/*!
\brief \brief_macro{2D vector type} \brief_macro_getset
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_2D_GET_SET, two-dimensional vector type}. \details_macro_getset
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Get0 \param_macro_getset{get, \macro_x}
\param Get1 \param_macro_getset{get, \macro_y}
\param Set0 \param_macro_getset{set, \macro_x}
\param Set1 \param_macro_getset{set, \macro_y}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_2D_GET_SET(Vector, CoordinateType, CoordinateSystem, Get0, Get1, Set0, Set1) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 2, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, 0, CoordinateType, Get0, Set0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, 1, CoordinateType, Get1, Set1) \
}}}

/*!
\brief \brief_macro{3D vector type} \brief_macro_getset
\ingroup register
\details \details_macro{BOOST_GEOMETRY_REGISTER_VECTOR_3D_GET_SET, three-dimensional vector type}. \details_macro_getset
\param Vector \param_macro_type{Vector}
\param CoordinateType \param_macro_coortype{vector}
\param CoordinateSystem \param_macro_coorsystem
\param Get0 \param_macro_getset{get, \macro_x}
\param Get1 \param_macro_getset{get, \macro_y}
\param Get2 \param_macro_getset{get, \macro_z}
\param Set0 \param_macro_getset{set, \macro_x}
\param Set1 \param_macro_getset{set, \macro_y}
\param Set2 \param_macro_getset{set, \macro_z}
*/
#define BOOST_GEOMETRY_REGISTER_VECTOR_3D_GET_SET(Vector, CoordinateType, CoordinateSystem, Get0, Get1, Get2, Set0, Set1, Set2) \
namespace boost { namespace geometry { namespace traits {  \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_TRAITS(Vector, 3, CoordinateType, CoordinateSystem) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, 0, CoordinateType, Get0, Set0) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, 1, CoordinateType, Get1, Set1) \
    BOOST_GEOMETRY_DETAIL_SPECIALIZE_VECTOR_ACCESS_GET_SET(Vector, 2, CoordinateType, Get2, Set2) \
}}}
