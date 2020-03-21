
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by Jorge Bárcena on December of 2020                               *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  j.barcenalumbreras@gmail.com                                               *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef BOID_HEADER
#define BOID_HEADER

#include "Model2D.hpp"
#include <SFML/Graphics.hpp>
#include "ComponentBehavior.hpp"


using namespace toolkit;

namespace FlockingSystem
{

    class Boid : public Model2D
    {

    public:

        ComponentBehavior            Behavior;               // Determina como se comporta el Boid

        static std::vector<Boid*>    instances;              //Instancias de los boids

        float                         radius;                 //Radio
                                      
        int                           vertex;                 //Numero de vertices
                                      
        std::vector< Point3f >        spherePoints;           //Vertices de la esfera en base con centro en (0,0)
                                                                            
        float                         translationSpeed;       //Velocidad de translacion


    public:

        /*
        * Contructor que recibe los parametros de como va a ser el boid en cuestion
        */
        Boid(
            float             _radius                                                  ,//Radio
            sf::Color         _color                                                   ,//Color
            Vector2f          _position                                                ,// Position
            float             _translationSpeed        = 1                             ,//Velocidad de translacion
            int               _vertex                  = 16                            )//Numero de vertices
        ;      

        /*
        * Divide la esfera en vertices de igual distancia
        */
        void setListOfPolygons();
      
        /*
        * Busca la siguiente posicion del Boid
        */
        void update(float delta); 
        

        void set_translationSpeed(float _speed)
        {
            translationSpeed = _speed;
        }


        /*
        * Llama a la funcion update() de todos los Boids almacenados
        */
        static void Update(float delta)
        {
            for (Boid* boid : instances)
            {
                boid->update(delta);
            }
        };

        /*
        * Llama a la funcion render() de todos los Boids almacenados
        */
        static void Render(sf::RenderWindow& renderer)
        {
            for (int i = (int)instances.size() - 1; i >= 0; --i)
            {
                
                instances[i]->render(renderer);
            }
        };

    };

}

#endif