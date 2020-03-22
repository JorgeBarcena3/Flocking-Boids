
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
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define WIDTH  1024
#define HEIGHT 720


using namespace sf;
using namespace FlockingSystem;


int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Flocking Boids - Jorge Barcena", sf::Style::Default, ContextSettings(32));

    window.setVerticalSyncEnabled(true);

    bool running = true;

    /* initialize random seed: */
    srand(time(NULL));

    std::vector<Boid*> agents;

    BoidInfo infoBoid(25, 50, 24, 0.2, 5);

    for (size_t i = 0; i < 200; i++)
    {
        agents.push_back(new Boid
        (
            6,
            sf::Color::White,
            { MathHelper::generateRandom(0, WIDTH), MathHelper::generateRandom(0, HEIGHT) },
            { WIDTH, HEIGHT },
            infoBoid,
            3
        )
        );

    }


    do
    {
        // Process window events:

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                running = false;
            }
        }

        Boid::Update(0);

        // Render:

        window.clear();

        Boid::Render(window);

        window.display();

    } while (running);

    for (auto boid : Boid::instances)
    {
        delete boid;
    }

    return EXIT_SUCCESS;
}

