
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

    class ComponentBehavior;

    /*
    * Informacin relativa a las caracteristicas de los boids
    */
    struct BoidInfo
    {
        float    alignPerceptionRadius     = 25   ;
        float    coeshionPerceptionRadius  = 50   ;
        float    avoidancePerceptionRadius = 24   ;

        Vector2f velocity                         ;
        Vector2f aceleration                      ;
        float    maxForce                  = 0.2f ;
        float    maxSpeed                  = 5    ;

        BoidInfo(
            float _alignPerceptionRadius,
            float _coeshionPerceptionRadius,
            float _avoidancePerceptionRadius,
            float _maxForce,
            float _maxSpeed
        )
        {

            alignPerceptionRadius     = _alignPerceptionRadius     ;
            coeshionPerceptionRadius  = _coeshionPerceptionRadius  ;
            avoidancePerceptionRadius = _avoidancePerceptionRadius ;
            maxForce                  = _maxForce                  ;
            maxSpeed                  = _maxSpeed                  ;

            velocity = toolkit::Vector2f({ MathHelper::generateRandom(0,10), MathHelper::generateRandom(0,10)});
            MathHelper::setMag(velocity, MathHelper::generateRandom(2, 4));
            aceleration = toolkit::Vector2f({0,0});
            
                
        }

    };

    /*
    * Maneja un objeto del tipo void
    */
    class Boid : public Model2D
    {

    public:

        static std::vector<Boid*>    instances;           //Instancias de los boids

        static sf::RenderWindow *    window;              // Instancia de la ventana de render

        static toolkit::Vector2f     window_size; // Tamaño de la pantalla


    public:

        BoidInfo                     boidInfo;         // Informacion con respecto al boid

        ComponentBehavior    *       behavior;         // Determina como se comporta el Boid
        
        float                         radius;          // Radio

    private:

                                      
        int                           vertex;          // Numero de vertices
                                      
        std::vector< Point3f >        spherePoints;    // Vertices de la esfera en base con centro en (0,0)

    public:

        /*
        * Contructor que recibe los parametros de como va a ser el boid en cuestion
        */
        Boid(
            float             _radius, 
            sf::Color         _color, 
            Vector2f          _startPosition,
            BoidInfo          _info,
            int               _vertex = 16
        );


        /*
        * Divide la esfera en vertices de igual distancia
        */
        void setListOfPolygons();
      
        /*
        * Busca la siguiente posicion del Boid
        */
        void update(float delta);

        /*
        * Si se sale de los limites de la pantalla lo reintroducimos por otro lado
        */
        void limits();

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