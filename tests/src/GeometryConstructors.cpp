
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
#include <boost/geometry/algorithms/make.hpp>
#include <boost/geometry/algorithms/equals.hpp>

namespace bg = boost::geometry;

BOOST_AUTO_TEST_SUITE(GeometryConstructors)

BOOST_AUTO_TEST_CASE(make_zero)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(0, 0);
    bg::model::vector<int, 2, bg::cs::cartesian> v2 = bg::make_zero< bg::model::vector<int, 2, bg::cs::cartesian> >();

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(make_2)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v2 = bg::make< bg::model::vector<int, 2, bg::cs::cartesian> >(4, 5);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(make_3)
{
    bg::model::vector<int, 3, bg::cs::cartesian> v1(4, 5, 6);
    bg::model::vector<int, 3, bg::cs::cartesian> v2 = bg::make< bg::model::vector<int, 3, bg::cs::cartesian> >(4, 5, 6);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_SUITE_END()
