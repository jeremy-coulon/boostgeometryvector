
//          Copyright Jeremy Coulon 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

//===========================
//==  BoostGeometryVector  ==
//===========================
#include <BoostGeometryVector/BoostGeometryVector.hpp>

//=============
//==  Boost  ==
//=============
#include <boost/test/unit_test.hpp>
#include <boost/geometry/algorithms/convert.hpp>

namespace bg = boost::geometry;

template< typename P >
struct myvector
{
    int x, y;
};

BOOST_GEOMETRY_REGISTER_VECTOR_2D(myvector, int, bg::cs::cartesian, x, y)

BOOST_AUTO_TEST_SUITE(Convert)

BOOST_AUTO_TEST_CASE(convert)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(5, 6);
    myvector< bg::model::point<int, 2, bg::cs::cartesian> > v2;
    bg::convert(v1, v2);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_SUITE_END()
