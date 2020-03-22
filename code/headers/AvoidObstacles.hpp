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

        float obstacleRadius = 50;

        toolkit::Vector2f obstaclePosition;
        
        bool obstacleInScreen();

        // Inherited via FlockBehavior
        virtual toolkit::Vector2f calculateMove(Boid* a) override;

    };

}

#endif
