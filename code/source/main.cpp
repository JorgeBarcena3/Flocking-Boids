
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
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace FlockingSystem;


float generateRandom(double M, double N)
{
    return M + (rand() / (RAND_MAX / (N - M)));
}


int main()
{
    RenderWindow window(VideoMode(900, 600), "Flocking Boids - Jorge Barcena", sf::Style::Default, ContextSettings(32));

    window.setVerticalSyncEnabled(true);

    bool running = true;

    /* initialize random seed: */
    srand(time(NULL));

    std::vector<Boid*> agents;

    for (size_t i = 0; i < 1000; i++)
    {
        agents.push_back( new Boid
            (
                3,
                sf::Color(255,255, generateRandom(100.0f, 255.0f), 255),
                { generateRandom(-1.f,1.0f), generateRandom(-1.f,1.f)},
                { generateRandom(0, 900), generateRandom(0, 600) },
                10,
                1,
                8
            )
        );

    }

    //agents.push_back(new Boid
    //(
    //    50,
    //    sf::Color::Red,
    //    { generateRandom(-1.f,1.0f), generateRandom(-1.f,1.f) },
    //    { generateRandom(0, 900), generateRandom(0, 600) },
    //    100,
    //    4,
    //    6
    //)
    //);
    //
    //agents.push_back(new Boid
    //(
    //    50,
    //    sf::Color(255, 255, generateRandom(100.0f, 255.0f), 255),
    //    { generateRandom(-1.f,1.0f), generateRandom(-1.f,1.f) },
    //    { generateRandom(0, 900), generateRandom(0, 600) },
    //    1,
    //    4,
    //    4
    //)
    //);





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

