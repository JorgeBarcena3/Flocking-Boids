
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
#include <TGUI/TGUI.hpp>


#define WIDTH  1024
#define HEIGHT 720


using namespace sf;
using namespace FlockingSystem;

void signalHandler(tgui::Widget::Ptr widget, const std::string& signalName)
{
    auto name = widget->getWidgetName();
    auto id = std::stoi(name.substring(7).toAnsiString());
    ComponentBehavior::weights[id] = widget->cast<tgui::Slider>()->getValue();

}


void setWidgets(std::vector<std::shared_ptr<tgui::Widget>>& sliderWidget, tgui::Gui& gui)
{

    float n_widget = (float)ComponentBehavior::weights.size();

    float spacing = WIDTH / (n_widget + 1);
    float min_spacing = spacing / (n_widget + 1);

    for (size_t i = 0; i < n_widget; i++)
    {
        auto slider = tgui::Slider::create(0.1f, 3.f);

        slider->setPosition((min_spacing * (i + 1)) + (spacing * i), HEIGHT - (HEIGHT * 0.1));
        slider->setSize(spacing, spacing * 0.1);
        slider->setStep(0.1f);
        slider->setValue(ComponentBehavior::weights[i]);
        slider->connect("ValueChanged", signalHandler);

        sliderWidget.push_back(slider);
        gui.add(sliderWidget[i], ("Slider_" + std::to_string(i)));

    }

}


int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Flocking Boids - Jorge Barcena", sf::Style::Default, ContextSettings(32));
    tgui::Gui gui{ window }; // Create the gui and attach it to the window

    std::vector<tgui::Widget::Ptr> sliderWidget;
    setWidgets(sliderWidget, gui);


    Boid::window = &window;
    Boid::window_size = toolkit::Vector2f({ WIDTH, HEIGHT });

    window.setVerticalSyncEnabled(true);

    bool running = true;

    /* initialize random seed: */
    srand(time(NULL));

    std::vector<Boid*> agents;

    BoidInfo infoBoid(25, 50, 24, 0.2f, 5);

    for (size_t i = 0; i < 200; i++)
    {
        agents.push_back(new Boid
        (
            6,
            sf::Color::White,
            { MathHelper::generateRandom(0, WIDTH), MathHelper::generateRandom(0, HEIGHT) },
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

            gui.handleEvent(event); // Pass the event to the widgets

        }

        Boid::Update(0);

        // Render:

        window.clear();

        Boid::Render(window);
        gui.draw(); // Draw all widgets


        window.display();

    } while (running);

    for (auto boid : Boid::instances)
    {
        delete boid;
    }

    return EXIT_SUCCESS;
}
