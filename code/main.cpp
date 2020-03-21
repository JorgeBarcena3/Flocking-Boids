
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                             *
 *  Started by Ángel on november of 2017                                       *
 *  Modified by Jorge Bárcena on December of 2020                              *
 *                                                                             *
 *  This is free software released into the public domain.                     *
 *                                                                             *
 *  angel.rodriguez@esne.edu                                                   *
 *  j.barcenalumbreras@gmail.com                                               *

 *                                                                             *
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "headers/Boid.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "main.h"

using namespace sf;
using namespace FlockingSystem;

int main()
{
	RenderWindow window(VideoMode(900, 600), "Flocking Boids - Jorge Barcena", sf::Style::Default, ContextSettings(32));

	window.setVerticalSyncEnabled(true);

	bool running = true;

	Boid* A = new Boid(25, sf::Color::Red, {450, 300}, 1);


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
