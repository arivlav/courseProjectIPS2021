#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    RenderWindow windows(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Frog crosses the road");

    while (windows.isOpen())
    {
        Event event;
        while (windows.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                windows.close();
            }
        }

        windows.clear();
        windows.display();
    }
}