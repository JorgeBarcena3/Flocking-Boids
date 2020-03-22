#include "../headers/Coeshion.hpp"
#include "../headers/Boid.hpp"

toolkit::Vector2f FlockingSystem::Coeshion::calculateMove(Boid * a)
{

    if (a->neighboursBoids.size() == 0)
        return toolkit::Vector2f({ 0,0 });
    

    toolkit::Vector2f cohesionMove({ 0,0 });

    for (auto agent : a->neighboursBoids)
    {
        cohesionMove[0] += agent->position[0];
        cohesionMove[1] += agent->position[1];
    }

    cohesionMove[0] /= a->neighboursBoids.size();
    cohesionMove[1] /= a->neighboursBoids.size();


    cohesionMove[0] -= a->position[0];
    cohesionMove[1] -= a->position[0];

    return cohesionMove;

}
