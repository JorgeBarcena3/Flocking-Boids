/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FLOCKBEHAVIOR_HEADER
#define FLOCKBEHAVIOR_HEADER

#include "Vector.hpp"

namespace FlockingSystem
{
    class Boid;

    class FlockBehavior
    {

    public:

        virtual toolkit::Vector2f calculateMove(Boid * a) = 0;

        ~FlockBehavior()
        {}

    };

}

#endif
