/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ALIGNMENT_HEADER
#define ALIGNMENT_HEADER

#include "FlockBehavior.hpp"

namespace FlockingSystem
{

    class Alignment : public FlockBehavior
    {

    public:


        // Inherited via FlockBehavior
        virtual toolkit::Vector2f calculateMove(Boid * a) override;

    };

}

#endif
