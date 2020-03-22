#include "ComponentBehavior.hpp"
#include "Coeshion.hpp"
#include "Avoidance.hpp"
#include "Alignment.hpp"

FlockingSystem::ComponentBehavior::ComponentBehavior(Boid* _agent) : agent(_agent)
{
    behaviors.push_back(new FlockingSystem::Coeshion());
    weights.push_back(1);

    behaviors.push_back(new FlockingSystem::Alignment());
    weights.push_back(1);

    behaviors.push_back(new FlockingSystem::Avoidance());
    weights.push_back(2);


}

