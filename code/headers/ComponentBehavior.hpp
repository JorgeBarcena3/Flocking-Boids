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

    class ComponentBehavior
    {

    private:

        Boid * agent;

        std::vector<FlockBehavior * > behaviors;

        std::vector<float> weights;

    public:

        ComponentBehavior(Boid* _agent);


        toolkit::Vector2f calculateMove()
        {

            toolkit::Vector2f move({ 0,0 });

            for (size_t i = 0; i < behaviors.size(); i++)
            {
                toolkit::Vector2f partialMove = behaviors[i]->calculateMove(agent);

                partialMove[0] *= weights[i];
                partialMove[1] *= weights[i];

                move[0] += partialMove[0];
                move[1] += partialMove[1];

            }

            return move;

        }

    };

}

#endif
