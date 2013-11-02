
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
#include <boost/geometry/algorithms/assign.hpp>

#include <boost/geometry/geometries/register/point.hpp>

namespace bg = boost::geometry;

template< typename P >
struct myvector
{
    int x, y;
};

BOOST_GEOMETRY_REGISTER_VECTOR_2D_TEMPLATED(myvector, int, bg::cs::cartesian, x, y)

BOOST_AUTO_TEST_SUITE(Assign)

BOOST_AUTO_TEST_CASE(assign)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(5, 6);
    myvector< bg::model::point<int, 2, bg::cs::cartesian> > v2;
    bg::assign(v2, v1);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(assign_zero)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(0, 0);
    bg::model::vector<int, 2, bg::cs::cartesian> v2(4, 5);
    bg::assign_zero(v2);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(assign_values_2)
{
    bg::model::vector<int, 2, bg::cs::cartesian> v1(4, 5);
    bg::model::vector<int, 2, bg::cs::cartesian> v2;
    bg::assign_values(v2, 4, 5);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(assign_values_3)
{
    bg::model::vector<int, 3, bg::cs::cartesian> v1(4, 5, 6);
    bg::model::vector<int, 3, bg::cs::cartesian> v2;
    bg::assign_values(v2, 4, 5, 6);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(assign_values_4)
{
    bg::model::vector<int, 4, bg::cs::cartesian> v1;
    bg::set<0>(v1, 4);
    bg::set<1>(v1, 5);
    bg::set<2>(v1, 6);
    bg::set<3>(v1, 7);
    bg::model::vector<int, 4, bg::cs::cartesian> v2;
    bg::assign_values(v2, 4, 5, 6, 7);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_SUITE_END()
