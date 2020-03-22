#include "../headers/Coeshion.hpp"
#include "../headers/Boid.hpp"

toolkit::Vector2f FlockingSystem::Coeshion::calculateMove(Boid * a)
{
    toolkit::Vector2f cohesionMove({ 0,0 });
    int total = 0;

    for (auto agent : Boid::instances)
    {
        float d = MathHelper::distance(agent->position, a->position);

        if (agent != a && d < a->boidInfo.coeshionPerceptionRadius)
        {
            cohesionMove += agent->position;
            total++;
        }
    }

    if (total > 0)
    {
        cohesionMove /= total;
        cohesionMove -= a->position;
        MathHelper::setMag(cohesionMove, a->boidInfo.maxSpeed);
        cohesionMove -= a->boidInfo.velocity;
        MathHelper::limit(cohesionMove, a->boidInfo.maxForce);

    }

    return cohesionMove;

}
