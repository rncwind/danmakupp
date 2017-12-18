#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Player : public sf::Drawable
{
public:
    Player(sf::Texture texture) : player_Texture(texture) {player_Sprite.setTexture(player_Texture);};
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.texture = &player_Texture;
        target.draw(player_Sprite, states);
    }
    void createSprite(sf::Sprite& player_Sprite, sf::Texture player_Texture){
        player_Sprite.setTexture(player_Texture);
    }
    sf::Sprite player_Sprite;
    sf::Texture player_Texture;
};
