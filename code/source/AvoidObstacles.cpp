#include "../headers/AvoidObstacles.hpp"
#include "../headers/Boid.hpp"
#include "../headers/Rotation.hpp"
#include "../headers/Translation.hpp"
#include "../headers/Transformation.hpp"
#include "../headers/Scaling.hpp"
#include <SFML\Window\Mouse.hpp>

using namespace sf;

bool FlockingSystem::AvoidObstacles::obstacleInScreen()
{
    sf::Vector2i position = sf::Mouse::getPosition(*(Boid::window));

    if (
        position.x > 0 && position.x < Boid::window_size[0] &&
        position.y > 0 && position.y < Boid::window_size[1] - (Boid::window_size[1] * 0.15f)
        )
    {
        obstaclePosition = toolkit::Vector2f({ position.x , position.y });
        return true;
    }

    return false;
}

toolkit::Vector2f FlockingSystem::AvoidObstacles::calculateMove(Boid* agent)
{

    toolkit::Vector2f collisionMove({ 0,0 });

    float d = MathHelper::distance(obstaclePosition, agent->position);

    if (d < obstacleRadius)
    {
        toolkit::Vector2f a = MathHelper::getDirection(obstaclePosition, agent->position);
        float angleA = tanf((MathHelper::magnitude(&(*agent).boidInfo.aceleration) / d));
        float angleB = tanf((obstacleRadius / d));

        if (angleA < angleB)
        {
            Vector2f origin = agent->position;

            agent->boidInfo.velocity[0] += (origin[0] * cosf(angleB)) - (origin[0] * sinf(angleB));
            agent->boidInfo.velocity[1] += (origin[1] * cosf(angleB)) + (origin[1] * sinf(angleB));

            MathHelper::limit(agent->boidInfo.velocity, agent->boidInfo.maxSpeed);
        }
       
    }


    return collisionMove;

}
