#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "player.h"
#include "enemy.h"

void eventHandler(Player& ship, std::vector<Enemy> enemyContainer);
void debugFuncs(std::vector<Enemy>& enemyContainer);

std::map<std::string,sf::Texture> textureMap;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600,800),"Danmaku");
    window.setVerticalSyncEnabled(true);

    sf::Texture playertex;
    sf::Texture enemytex;
    if(!playertex.loadFromFile("Resources/ikaruga.png"))
        std::cerr << "failed to load player sprite!\n";
    if(!enemytex.loadFromFile("Resources/caco.png"))
        std::cerr << "Failed to load enemy sprite!\n";

    textureMap.emplace("player", playertex);
    textureMap.emplace("enemy",  enemytex);

    Player ship(textureMap.at("player"));

    std::vector<Enemy> enemyContainer;
    while (window.isOpen())
    {
        eventHandler(ship,enemyContainer);
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        debugFuncs(enemyContainer);
        window.clear(sf::Color::Black);
        window.draw(ship);
        for(auto& e : enemyContainer)
            window.draw(e);
        window.display();
    }
}

void debugFuncs(std::vector<Enemy>& enemyContainer)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && enemyContainer.size() < 1){
        enemyContainer.emplace_back(textureMap.at("enemy"));
    }
}
