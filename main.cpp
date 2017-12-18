#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600,800),"Danmaku");
    window.setVerticalSyncEnabled(true);
    
    sf::Texture playertex;
    if(!playertex.loadFromFile("Resources/ikaruga.png"))
        std::cerr << "failed to load player sprite!\n";
    Player ship(playertex);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(ship);
        window.display();
    }
}
