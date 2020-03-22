#include "../headers/Avoidance.hpp"
#include "../headers/Boid.hpp"
#include "../headers/MathHelper.hpp"

toolkit::Vector2f FlockingSystem::Avoidance::calculateMove(Boid* a)
{

    if (a->neighboursBoids.size() == 0)
        return toolkit::Vector2f({ 0,0 });


    toolkit::Vector2f avoidanceMove({ 0,0 });
    int nAvoid = 0;

    for (auto agent : a->neighboursBoids)
    {
        auto diff = MathHelper::getDirection((agent->position), (a->position));
        auto d = MathHelper::magnitude(&diff);

        diff[0] /= d;
        diff[1] /= d;

        avoidanceMove[0] += agent->position[0];
        avoidanceMove[1] += agent->position[1];
    }


    avoidanceMove[0] /= a->neighboursBoids.size();
    avoidanceMove[1] /= a->neighboursBoids.size();



    return avoidanceMove;


}
