
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
#include <boost/geometry/algorithms/disjoint.hpp>
#include <boost/geometry/algorithms/equals.hpp>

namespace bg = boost::geometry;

BOOST_AUTO_TEST_SUITE(Predicates)

BOOST_AUTO_TEST_CASE(disjoint)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v2(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v3(6, 5);

    BOOST_CHECK(!bg::disjoint(v1, v2));
    BOOST_CHECK(bg::disjoint(v1, v3));
}

BOOST_AUTO_TEST_CASE(equals)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v2(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v3(6, 5);

    BOOST_CHECK(bg::equals(v1, v2));
    BOOST_CHECK(!bg::equals(v1, v3));
}

BOOST_AUTO_TEST_SUITE_END()
