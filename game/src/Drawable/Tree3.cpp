#include "Tree3.h"

Tree3::Tree3(sf::Vector2i pos)
:Drawable()
{
    m_type = 2;

    m_texture.loadFromFile("resource/map/arbre3.png");
    m_sprite.setTexture(m_texture);

    m_pos = pos;
    m_position = sf::Vector2f(pos.x - m_texture.getSize().x/2, pos.y - m_texture.getSize().y/2);
    m_positionCenter = sf::Vector2f(pos.x+m_texture.getSize().x/2, pos.y+m_texture.getSize().y/2);

    m_sprite.setPosition(m_position);

    m_rect.left = pos.x + 20;
    m_rect.top = pos.y;
    m_rect.width = m_texture.getSize().x - 20;
    m_rect.height = m_texture.getSize().y;
}

Tree3::~Tree3()
{
    //dtor
}
