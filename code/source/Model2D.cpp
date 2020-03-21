
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
*                                                                             *
*  Started by �ngel on november of 2017                                       *
*                                                                             *
*  This is free software released into the public domain.                     *
*                                                                             *
*  angel.rodriguez@esne.edu                                                   *
*                                                                             *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "../headers/Model2D.hpp"
#include "../headers/Scaling.hpp"
#include "../headers/Rotation.hpp"
#include "../headers/Translation.hpp"

using namespace sf;
using namespace toolkit;

namespace FlockingSystem
{

    void Model2D::render(sf::RenderWindow& renderer)
    {
        Scaling2f        scale(scale);
        Rotation2f       rotation(angle);
        Translation2f    translation(position);
        Transformation2f transform(translation * rotation * scale);

        int number_of_vertices = local_vertices.size();

        for (size_t i = 0; i < number_of_vertices; ++i)
        {
            transformed_vertices[i] = Matrix33f(transform) * Matrix31f(local_vertices[i]);
        }

        ConvexShape sfml_polygon;

        sfml_polygon.setPointCount(number_of_vertices);

        if (tx != nullptr)
            sfml_polygon.setTexture(tx);
        else
            sfml_polygon.setFillColor(polygonColor);


        for (int i = 0; i < number_of_vertices; i++)
        {
            sfml_polygon.setPoint
            (
                i,
                sf::Vector2f
                (
                    transformed_vertices[i][0],
                    transformed_vertices[i][1]
                )
            );
        }

        renderer.draw(sfml_polygon);
    }


}
