
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
#include <boost/geometry/algorithms/length.hpp>

namespace bg = boost::geometry;

const float EPSILON = 1e-12f;

BOOST_AUTO_TEST_SUITE(Length)

BOOST_AUTO_TEST_CASE(length)
{
    bg::model::vector<float, 2, bg::cs::cartesian> v(3.0f, 0);

    float l = bg::length(v);

    BOOST_CHECK_CLOSE(l, 3.0f, EPSILON);
}

BOOST_AUTO_TEST_CASE(comparable_length)
{
    bg::model::vector<float, 2, bg::cs::cartesian> v(3.0f, 0);

    float l = bg::comparable_length(v);

    BOOST_CHECK_CLOSE(l, 9.0f, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
