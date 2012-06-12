
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
#include <boost/geometry/arithmetic/dot_product.hpp>

namespace bg = boost::geometry;

BOOST_AUTO_TEST_SUITE(Products)

BOOST_AUTO_TEST_CASE(dot_product)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(1, 1);
    bg::model::vector<int, 2, bg::cs::cartesian> v2(1, 2);

    BOOST_CHECK_EQUAL(bg::dot_product(v1, v2), 3);
}

BOOST_AUTO_TEST_SUITE_END()
