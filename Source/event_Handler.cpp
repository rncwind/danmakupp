#include <iostream>
#include "player.h"
#include "enemy.h"

void handleInput(Player& ship);
void handleCollision(Player& ship, std::vector<Enemy> enemyContainer);

void eventHandler(Player& ship, std::vector<Enemy> enemyContainer)
{
    handleInput(ship);
    handleCollision(ship,enemyContainer);
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

void handleCollision(Player& ship, std::vector<Enemy> enemyContainer)
{
    for(auto& e : enemyContainer)
    {
        if(ship.getBounds().intersects(e.getBounds())){
            std::cout << "\nCOLLISION\n";
        }
    }
}
