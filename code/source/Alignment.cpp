#include "../headers/Alignment.hpp"
#include "../headers/Boid.hpp"

toolkit::Vector2f FlockingSystem::Alignment::calculateMove(Boid* a)
{

    toolkit::Vector2f alignmentMove({ 0,0 });
    int total = 0;

    for (auto agent : Boid::instances)
    {
        float d = MathHelper::distance(agent->position, a->position);

        if (agent != a && d < a->boidInfo.alignPerceptionRadius)
        {
            alignmentMove += agent->boidInfo.velocity;
            total++;
        }
    }

    if (total > 0)
    {
        alignmentMove /= total;
        MathHelper::setMag(alignmentMove, a->boidInfo.maxSpeed);
        alignmentMove -= a->boidInfo.velocity;
        MathHelper::limit(alignmentMove, a->boidInfo.maxForce);

    }

    return alignmentMove;

}
