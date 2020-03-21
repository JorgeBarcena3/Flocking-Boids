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
#include <vector>

namespace FlockingSystem
{

    class ComponentBehavior
    {

    private:

        Boid * agent;

        std::vector<FlockBehavior> behaviors;

    public:

        ComponentBehavior(Boid * _agent) : agent(_agent)
        {
                
        }


        void update()
        {

            for (size_t i = 0; i < behaviors.size(); i++)
            {
                behaviors[i].calculateMove(agent);
            }

        }

    };

}

#endif
