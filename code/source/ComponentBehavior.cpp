#include "../headers/ComponentBehavior.hpp"
#include "../headers/Coeshion.hpp"
#include "../headers/Avoidance.hpp"
#include "../headers/Alignment.hpp"
#include "../headers/Boid.hpp"


std::vector<float> FlockingSystem::ComponentBehavior::weights = {1.5f, 1.0f, 2.5f};


FlockingSystem::ComponentBehavior::ComponentBehavior(Boid* _agent) : agent(_agent)
{

    behaviors.push_back(new FlockingSystem::Alignment());

    behaviors.push_back(new FlockingSystem::Coeshion());

    behaviors.push_back(new FlockingSystem::Avoidance());

    avoidObstacleBehaviors = new FlockingSystem::AvoidObstacles();


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
        behaviorsPartialMove[i] *= FlockingSystem::ComponentBehavior::weights[i];

        agent->boidInfo.aceleration += behaviorsPartialMove[i];

    }

    if (avoidObstacleBehaviors->obstacleInScreen())
        toolkit::Vector2f avoid = avoidObstacleBehaviors->calculateMove(agent);



}
