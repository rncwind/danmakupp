#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "enemy.h"

std::map<std::string,sf::Texture> textureMap;

void handleInput(Player& ship);
void handleCollision(Player& ship, Player& testEnemy);

int main()
{
    sf::RenderWindow window(sf::VideoMode(600,800),"Danmaku");
    window.setVerticalSyncEnabled(true);
    
    sf::Texture playertex;
    if(!playertex.loadFromFile("Resources/ikaruga.png"))
        std::cerr << "failed to load player sprite!\n";
    Player ship(playertex);
    Player testEnemy(playertex);
    testEnemy.setPosition(300,400);
    testEnemy.updateSprite();
    while (window.isOpen())
    {
        handleInput(ship);
        handleCollision(ship,testEnemy);
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(ship);
        window.draw(testEnemy);
        window.display();
    }
}

void eventHander(Player& ship, std::vector<Enemy> enemyContainer)
{

}

void handleInput(Player& ship)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        ship.movedown();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        ship.moveUp();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        ship.moveRight();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        ship.moveLeft();
}

void handleCollision(Player& ship, Player& testEnemy)
{
    if(ship.getBounds().intersects(testEnemy.getBounds())){
        std::cout << "\n\nCOLLISION\n\n";
    }
}

