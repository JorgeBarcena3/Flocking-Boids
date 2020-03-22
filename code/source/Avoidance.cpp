#include "../headers/Avoidance.hpp"
#include "../headers/Boid.hpp"
#include "../headers/MathHelper.hpp"

toolkit::Vector2f FlockingSystem::Avoidance::calculateMove(Boid* a)
{

    toolkit::Vector2f avoidanceMovement({ 0,0 });
    int total = 0;

    for (auto agent : Boid::instances)
    {
        float d = MathHelper::distance(agent->position, a->position);

        if (agent != a && d < a->boidInfo.avoidancePerceptionRadius)
        {
            auto diff = a->position;
            diff -= agent->position;

            diff /= powf(d, 2);

            avoidanceMovement += diff;
            total++;
        }
    }

    if (total > 0)
    {
        avoidanceMovement /= total;
        MathHelper::setMag(avoidanceMovement, a->boidInfo.maxSpeed);
        avoidanceMovement -= a->boidInfo.velocity;
        MathHelper::limit(avoidanceMovement, a->boidInfo.maxForce);

    }

    return avoidanceMovement;


}
