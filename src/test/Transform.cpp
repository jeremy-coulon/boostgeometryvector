
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
#include <boost/geometry/algorithms/transform.hpp>
#include <boost/geometry/strategies/transform/inverse_transformer.hpp>
#include <boost/geometry/strategies/transform/matrix_transformers.hpp>

namespace bg = boost::geometry;

BOOST_AUTO_TEST_SUITE(Transform)

BOOST_AUTO_TEST_SUITE(WithStrategy)

BOOST_AUTO_TEST_CASE(translate_transformer)
{
    typedef bg::model::vector<int, 2, bg::cs::cartesian> Vector;

    Vector v1(2, 2);
    Vector v2;

    bg::strategy::transform::translate_transformer< Vector, Vector > translation(2, 6);
    bg::transform(v1, v2, translation);

    BOOST_CHECK(bg::equals(v1, v2));
}

BOOST_AUTO_TEST_CASE(scale_transformer)
{
    typedef bg::model::vector<int, 2, bg::cs::cartesian> Vector;

    Vector v1(3, 4);
    Vector v2(6, 24);
    Vector v3;

    bg::strategy::transform::scale_transformer< Vector, Vector > scale(2, 6);
    bg::transform(v1, v3, scale);

    BOOST_CHECK(bg::equals(v2, v3));
}

BOOST_AUTO_TEST_CASE(rotate_transformer)
{
    typedef bg::model::vector<int, 2, bg::cs::cartesian> Vector;

    Vector v1(2, 2);
    Vector v2(-2, 2);
    Vector v3;

    bg::strategy::transform::rotate_transformer< Vector, Vector, bg::degree > rotation(-90.0);
    bg::transform(v1, v3, rotation);

    BOOST_CHECK(bg::equals(v2, v3));
}

BOOST_AUTO_TEST_CASE(ublas_transformer)
{
    typedef bg::model::vector<int, 2, bg::cs::cartesian> Vector;

    Vector v1(2, 2);
    Vector v2(-2, 2);
    Vector v3;

    bg::strategy::transform::rotate_transformer< Vector, Vector, bg::degree > rotation(-90.0);
    bg::strategy::transform::translate_transformer< Vector, Vector > translation(2, 6);

    boost::numeric::ublas::matrix<int> m = boost::numeric::ublas::prod(rotation.matrix(), translation.matrix());
    bg::strategy::transform::ublas_transformer< Vector, Vector, 2, 2 > transformation(m);

    bg::transform(v1, v3, transformation);

    BOOST_CHECK(bg::equals(v2, v3));
}

BOOST_AUTO_TEST_CASE(inverse_transformer)
{
    typedef bg::model::vector<int, 2, bg::cs::cartesian> Vector;

    Vector v1(2, 2);
    Vector v2(2, -2);
    Vector v3;

    bg::strategy::transform::rotate_transformer< Vector, Vector, bg::degree > rotation(-90.0);
    bg::strategy::transform::translate_transformer< Vector, Vector > translation(2, 6);

    boost::numeric::ublas::matrix<int> m = boost::numeric::ublas::prod(rotation.matrix(), translation.matrix());
    bg::strategy::transform::ublas_transformer< Vector, Vector, 2, 2 > transformation(m);
    bg::strategy::transform::inverse_transformer<Vector, Vector> inverse_transformation(transformation);

    bg::transform(v1, v3, inverse_transformation);

    BOOST_CHECK(bg::equals(v2, v3));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(WithoutStrategy)

BOOST_AUTO_TEST_CASE(degree_radian)
{
    // TODO
}

BOOST_AUTO_TEST_CASE(spherical_cartesian)
{
    // TODO
}

BOOST_AUTO_TEST_CASE(degree_radian_with_radius)
{
    // TODO
}

BOOST_AUTO_TEST_CASE(spherical_cartesian_with_radius)
{
    // TODO
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

