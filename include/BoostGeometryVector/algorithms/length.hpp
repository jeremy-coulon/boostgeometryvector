//          Copyright Jeremy Coulon 2012-2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

//===========================
//==  BoostGeometryVector  ==
//===========================
#include "BoostGeometryVector/core/tags.hpp"
#include "BoostGeometryVector/strategies/length.hpp"

//=============
//==  Boost  ==
//=============
#include <boost/geometry/strategies/default_length_result.hpp>
#include <boost/geometry/strategies/distance.hpp>
#include <boost/geometry/algorithms/length.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost
{
    namespace geometry
    {
#ifndef DOXYGEN_NO_DETAIL
        namespace detail
        {
            namespace length
            {

                template <typename Vector>
                struct vector_length
                {
                    template <typename Strategy>
                    static inline typename default_length_result<Vector>::type apply(
                            Vector const& v, Strategy const& strategy)
                    {
                        return strategy.apply(v);
                    }
                };

            } // namespace length
        } // namespace detail
#endif

#ifndef DOXYGEN_NO_DISPATCH
        namespace dispatch
        {

            template <typename Geometry>
            struct length<Geometry, vector_tag>
            {
                template <typename Strategy>
                static inline typename default_length_result<Geometry>::type apply(
                        Geometry const& g, Strategy const& /*strategy*/)
                {
                    // The provided stategy given by Boost is wrong !
                    // It is a distance strategy but we want a length strategy.
                    // Compute a default length strategy.
                    // 2 strategies are available : pythagoras and comparable::pythagoras
                    // Try to determine from strategy argument if we want a length or comparable::length strategy.

                    // Default length strategy
                    typedef typename strategy::length::services::default_strategy
                        <
                            vector_tag, Geometry
                        >::type default_length_strategy;

                    // Default comparable::length strategy
                    typedef typename strategy::length::services::comparable_type<
                                default_length_strategy
                            >::type default_comparable_length_strategy;

                    typedef typename mpl::if_<
                                is_same< default_length_strategy, Strategy >,                                           // if Strategy == default_length_strategy {
                                default_length_strategy,                                                                //   return default_length_strategy
                                typename mpl::if_<                                                                      // } else {
                                    is_same< default_comparable_length_strategy, Strategy >,                            //   if Strategy == default_comparable_length_strategy {
                                    default_comparable_length_strategy,                                                 //     return default_comparable_length_strategy
                                    typename mpl::if_<                                                                  //   } else {
                                        is_same< strategy::distance::services::comparable_type<Strategy> , Strategy >,  //     if Strategy == comparable::distance {
                                        default_comparable_length_strategy,                                             //       return default_comparable_length_strategy
                                        default_length_strategy                                                         //     } else { return default_length_strategy }
                                    >::type                                                                             //   }
                                >::type                                                                                 // }
                            >::type strategy_type;


                    return detail::length::vector_length<Geometry>::apply(g, strategy_type());
                }
            };

        } // namespace dispatch
#endif
    } // namespace geometry
} // namespace boost
