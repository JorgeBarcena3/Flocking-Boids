/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef COESHION_HEADER
#define COESHION_HEADER

#include "FlockBehavior.hpp"

namespace FlockingSystem
{

    class Avoidance : public FlockBehavior
    {

    public:


        // Inherited via FlockBehavior
        virtual void calculateMove(Boid * a) override;

    };

}

#endif
