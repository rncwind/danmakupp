#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Player : public sf::Drawable, public sf::Transformable
{
public:
    Player(sf::Texture texture) : player_Texture(texture)
    {player_Sprite.setTexture(player_Texture);};

    void movedown(){
        this->move(sf::Vector2f(0,10));
        updateSprite();
    }
    void moveUp(){
        this->move(sf::Vector2f(0,-10)); 
        updateSprite();
    }
    void moveLeft(){
        this->move(sf::Vector2f(-10,0));
        updateSprite();
    }
    void moveRight(){
        this->move(sf::Vector2f(10,0));
        updateSprite();
    }
    sf::FloatRect getBounds(){
        return player_Sprite.getGlobalBounds();
    }
    void updateSprite(){
        player_Sprite.setPosition(this->getPosition());
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.texture = &player_Texture;
        target.draw(player_Sprite, states);
    }
    sf::Sprite player_Sprite;
    sf::Texture player_Texture;
};
