#include "Barrack1.h"

Barrack1::Barrack1(sf::Vector2i pos)
:Drawable()
{
    m_imgLink = "resource/menuIG/barrack1.png";

    m_unitsList[0] = 1;

    m_type = 12;

    m_texture.loadFromFile("resource/map/barrack1.png");
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

Barrack1::~Barrack1()
{
    //dtor
}
