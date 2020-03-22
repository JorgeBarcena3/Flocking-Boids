
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge B�rcena on December of 2020                               *
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

sf::RenderWindow* Boid::window = nullptr;

toolkit::Vector2f Boid::window_size = toolkit::Vector2f({0,0});

/*
* Divide la esfera en vertices de igual distancia
*/
FlockingSystem::Boid::Boid(
    float             _radius,
    sf::Color         _color,
    Vector2f          _startPosition,
    BoidInfo          _info,
    int               _vertex) : Model2D({ }), boidInfo(_info)
{

    behavior = new ComponentBehavior(this);
    radius = _radius;                                    // Radio
    vertex = _vertex;                                    // Numero de vertices
    set_color(_color);                                   // Color que adopta
    set_position(_startPosition[0], _startPosition[1]);  // Posicionamos el boid en esa posicion
    setListOfPolygons();                                 // Creamos la esfera basandonos en los vertices


    /* Inicializamos los vertices */

    local_vertices.clear();
    transformed_vertices.clear();

    local_vertices.reserve(spherePoints.size());

    for (auto& point : spherePoints)
    {
        local_vertices.push_back(point);
    }

    transformed_vertices.resize(local_vertices.size());

    Boid::instances.push_back(this);                     //A�adimos el objeto a la lista de entidades



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
    //Restablecemos los limites
    limits();

    behavior->calculateMove();

    Vector2f newPows = position;
    newPows += boidInfo.velocity;

    boidInfo.velocity += boidInfo.aceleration;
    MathHelper::limit( boidInfo.velocity, boidInfo.maxSpeed );
    boidInfo.aceleration *= 0;

    set_position(newPows[0], newPows[1]);

    Model2D::update(delta);
};

void Boid::limits()
{
    if (position[0] < 0)
    {
        position[0] = Boid::window_size[0];
    }
    else if (position[0] > Boid::window_size[0])
    {
        position[0] = 0;

    }

    if (position[1] < 0)
    {
        position[1] = Boid::window_size[1];
    }
    else if (position[1] > Boid::window_size[1])
    {
        position[1] = 0;
    }
}
