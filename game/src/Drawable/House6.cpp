#include "House6.h"

House6::House6(sf::Vector2i pos)
{
    m_type = 25;

    m_texture.loadFromFile("resource/map/house6.png");
    m_sprite.setTexture(m_texture);

    m_pos = pos;
    m_position = sf::Vector2f(pos.x - m_texture.getSize().x/2, pos.y - m_texture.getSize().y/2);
    m_positionCenter = sf::Vector2f(pos.x+m_texture.getSize().x/2, pos.y+m_texture.getSize().y/2);

    m_rect.left = pos.x;
    m_rect.top = pos.y;
    m_rect.width = 5;
    m_rect.height = 5;

    m_sprite.setPosition(m_position);
}

House6::~House6()
{
    //dtor
}
