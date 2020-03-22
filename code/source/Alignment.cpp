#include "../headers/Alignment.hpp"
#include "../headers/Boid.hpp"

toolkit::Vector2f FlockingSystem::Alignment::calculateMove(Boid * a)
{

    if (a->neighboursBoids.size() == 0)
        return toolkit::Vector2f({ 0,0 });


    toolkit::Vector2f alignmentMove({ 0,0 });

    for (auto agent : a->neighboursBoids)
    {
        alignmentMove[0] += agent->direction[0];
        alignmentMove[1] += agent->direction[1];
    }

    alignmentMove[0] /= a->neighboursBoids.size();
    alignmentMove[1] /= a->neighboursBoids.size();


    return alignmentMove;

}
