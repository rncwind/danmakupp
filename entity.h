#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class gameEntity : public sf::Drawable, public sf::Transformable
{
public:

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.texture = &entity_Texture;
        target.draw(entity_Sprite, states);
    }
    virtual void createSprite(sf::Sprite& entity_Sprite, sf::Texture entity_Texture){
        entity_Sprite.setTexture(entity_Texture);
    }
protected:
    sf::Sprite  entity_Sprite;
    sf::Texture entity_Texture;
};
