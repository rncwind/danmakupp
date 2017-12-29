#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Enemy : public sf::Drawable, public sf::Transformable
{
public:
    Enemy(sf::Texture texture) : enemy_Texture(texture)
    { enemy_Sprite.setTexture(enemy_Texture); };
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.texture = &enemy_Texture;
        target.draw(enemy_Sprite, states);
    }
    sf::Sprite  enemy_Sprite;
    sf::Texture enemy_Texture;
};
