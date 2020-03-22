/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef AVOIDOBSTACLES_HEADER
#define AVOIDOBSTACLES_HEADER

#include "FlockBehavior.hpp"

namespace FlockingSystem
{

    class AvoidObstacles : public FlockBehavior
    {

    public:


        // Inherited via FlockBehavior
        virtual toolkit::Vector2f calculateMove(Boid* a) override;

    };

}

#endif
