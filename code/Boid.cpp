
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "headers/Boid.hpp"

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
    float _angularSpeed,
    sf::Color _color,
    Vector2f _position,
    float _translationSpeed,
    int _vertex) : Model2D({ })
{


    radius = _radius;                          // Radio
    vertex = _vertex;                          // Numero de vertices
    set_color(_color);                         // Color que adopta
    translationSpeed = _translationSpeed;      // Velocidad de translacion
    set_position(_position[0], _position[1]);  // Posicion actual 
    setListOfPolygons();                       // Creamos la esfera basandonos en los vertices


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

	float vertexAngle  = (float)( PI2 / vertex );       // Division de la esfera en X radianes
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

    set_position(position[0] + 1, position[1]);
	Model2D::update(delta);
};




