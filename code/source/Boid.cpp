
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Boid.hpp"
#include "../headers/MathHelper.hpp"

#define PI   3.1415
#define PI2  2 * PI
#define RAD  PI / 180

using namespace FlockingSystem;
using namespace sf;


//Inicializacion de la lista de boids
std::vector<Boid*> Boid::instances = {};

/*
* Divide la esfera en vertices de igual distancia
*/
FlockingSystem::Boid::Boid(
    float _radius,
    sf::Color _color,
    Vector2f _direction,
    Vector2f _startPosition,
    float _visibleRadius,
    float _translationSpeed,
    int _vertex) : Model2D({ }), Behavior(this)
{


    radius = _radius;                          // Radio
    vertex = _vertex;                          // Numero de vertices
    set_color(_color);                         // Color que adopta
    translationSpeed = _translationSpeed;      // Velocidad de translacion
    set_position(_startPosition[0], _startPosition[1]);
    visibleRadius = radius + _visibleRadius;
    direction = _direction;
    setListOfPolygons();                       // Creamos la esfera basandonos en los vertices

    radiusInfo.squareMaxSpeed = _translationSpeed * _translationSpeed;
    radiusInfo.squareNeighborRadius = visibleRadius * visibleRadius;
    radiusInfo.squareAvoidanceRadius = radiusInfo.squareNeighborRadius * 2 * 2;


    /* Inicializamos los vertices */

    local_vertices.clear();
    transformed_vertices.clear();

    local_vertices.reserve(spherePoints.size());

    for (auto& point : spherePoints)
    {
        local_vertices.push_back(point);
    }

    transformed_vertices.resize(local_vertices.size());

    Boid::instances.push_back(this); //Añadimos el objeto a la lista de entidades

}

void Boid::setListOfPolygons()
{

    float vertexAngle = (float)(PI2 / vertex);       // Division de la esfera en X radianes
    spherePoints = {};                           // Puntos de la esfera

    for (int i = 0; i < vertex; ++i)
    {
        float x = cosf(vertexAngle * i) * radius;
        float y = sinf(vertexAngle * i) * radius;
        spherePoints.push_back(Point3f({ x, y, 1 }));

    }

};

/*
* Busca la siguiente posicion del Boid
*/
void Boid::update(float delta)
{
    //fixLimits();

    getAgentsInRange();

    toolkit::Vector2f move = Behavior.calculateMove();

    move[0] *= translationSpeed;
    move[1] *= translationSpeed;

    if (MathHelper::sqrtMagnitude(move) > radiusInfo.squareMaxSpeed)
    {
        MathHelper::normalize(&move);
        move[0] *= translationSpeed;
        move[1] *= translationSpeed;
    }

    direction += move;
    MathHelper::normalize(&direction);

    direction[0] *= translationSpeed;
    direction[1] *= translationSpeed;

    /*  agent.Move(move);
      MathHelper::normalize(&direction);*/


    set_position(position[0] + direction[0], position[1] + direction[1]);

    Model2D::update(delta);
};

void Boid::fixLimits()
{
    if (position[0] < 0)
    {
        position[0] = 900;
    }
    else if (position[0] > 900)
    {
        position[0] = 0;

    }

    if (position[1] < 0)
    {
        position[1] = 600;
    }
    else if (position[1] > 600)
    {
        position[1] = 0;
    }
}

void Boid::getAgentsInRange()
{

    neighboursBoids.clear();

    for (Boid* agent : Boid::instances)
    {

        if (agent != this)
        {
            Vector2f agentFixedPosition = (*agent).position;
           

            float distance = MathHelper::distance(this->position, agentFixedPosition);

            if (distance < visibleRadius)
            {
                neighboursBoids.push_back(agent);
            }

        }



    }

    int r = 12 * neighboursBoids.size();
    set_color(sf::Color(255, 0, 0, 255));



}

