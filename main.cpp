#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!"); //,sf::Style::Fullscreen en param�tre de window pour un fullscreen qui pique aux yeux
    sf::CircleShape shape(100.f, 4);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}