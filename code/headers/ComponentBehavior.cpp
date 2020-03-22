#include "ComponentBehavior.hpp"
#include "Coeshion.hpp"
#include "Avoidance.hpp"
#include "Alignment.hpp"
#include "Boid.hpp"

FlockingSystem::ComponentBehavior::ComponentBehavior(Boid* _agent) : agent(_agent)
{

    behaviors.push_back(new FlockingSystem::Alignment());
    weights.push_back(1.5);

    behaviors.push_back(new FlockingSystem::Coeshion());
    weights.push_back(1);   

    behaviors.push_back(new FlockingSystem::Avoidance());
    weights.push_back(2.5);


}

void FlockingSystem::ComponentBehavior::calculateMove()
{

    std::vector<toolkit::Vector2f> behaviorsPartialMove(behaviors.size());

    for (size_t i = 0; i < behaviors.size(); i++)
    {
        behaviorsPartialMove[i] = behaviors[i]->calculateMove(agent);
    }

    for (size_t i = 0; i < behaviorsPartialMove.size(); i++)
    {
        behaviorsPartialMove[i] *= weights[i];

        agent->boidInfo.aceleration += behaviorsPartialMove[i];

    }

}
