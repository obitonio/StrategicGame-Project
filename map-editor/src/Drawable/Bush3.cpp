#include "Bush3.h"

Bush3::Bush3(sf::Vector2i pos)
{
    m_isNeutral = true;
    m_type = 6;

    m_texture.loadFromFile("resource/map/buisson4.png");
    m_sprite.setTexture(m_texture);

    m_pos = pos;
    m_position = sf::Vector2f(pos.x - m_texture.getSize().x/2, pos.y - m_texture.getSize().y/2);
    m_positionCenter = sf::Vector2f(pos.x+m_texture.getSize().x/2, pos.y+m_texture.getSize().y/2);

    m_rect.left = pos.x;
    m_rect.top = pos.y;
    m_rect.width = m_texture.getSize().x;
    m_rect.height = m_texture.getSize().y;

    m_sprite.setPosition(m_position);
}

Bush3::~Bush3()
{
    //dtor
}
