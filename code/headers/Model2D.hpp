
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by �ngel on november of 2017                                       *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  angel.rodriguez@esne.edu                                                   *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MODEL2D_HEADER
#define MODEL2D_HEADER

#include <vector>
#include "Point.hpp"
#include "Vector.hpp"
#include <SFML\Graphics\Color.hpp>
#include <SFML/Graphics.hpp>


using namespace toolkit;
namespace sf { class RenderWindow; }

namespace FlockingSystem
{

    using toolkit::Point3f;
    using toolkit::Vector2f;

    class Model2D
    {

    public:

        typedef std::vector< Point3f > Vertex_Buffer;

       
        // Atributos de transformaci�n:

        Vector2f	  position;
        float		  angle;
        float		  scale;

        // Atributos de animaci�n:

        sf::Color     polygonColor;



    public:

        Model2D()
        {
           

        }


        void set_position(float x, float y)
        {
            position = Vector2f({ x, y });
        }

        void set_angle(float new_angle)
        {
            angle = new_angle;
        }

        void set_scale(float new_scale)
        {
            scale = new_scale;
        }

        void set_color(sf::Color new_color)
        {
            polygonColor = new_color;
        }

        void update(float delta)
        {
        }

        void render();

    };

}

#endif
