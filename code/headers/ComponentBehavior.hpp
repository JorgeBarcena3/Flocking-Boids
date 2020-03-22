/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef COMPONENTBEHAVIOR_HEADER
#define COMPONENTBEHAVIOR_HEADER

#include "FlockBehavior.hpp"
#include "MathHelper.hpp"
#include <vector>

namespace FlockingSystem
{
    class Boid;

    class ComponentBehavior
    {

    private:

        FlockingSystem::Boid * agent;

        std::vector<FlockBehavior * > behaviors;

        std::vector<float> weights;

    public:

        ComponentBehavior(FlockingSystem::Boid* _agent);


        void calculateMove();

    };

}

#endif
