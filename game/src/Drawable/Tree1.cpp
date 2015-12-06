#include "Tree1.h"

Tree1::Tree1(sf::Vector2i pos)
:Drawable()
{
    m_type = 0;

    m_texture.loadFromFile("resource/map/arbre1.png");
    m_sprite.setTexture(m_texture);

    m_pos = pos;
    m_position = sf::Vector2f(pos.x - m_texture.getSize().x/2, pos.y - m_texture.getSize().y/2);
    m_positionCenter = sf::Vector2f(pos.x+m_texture.getSize().x/2, pos.y+m_texture.getSize().y/2);

    m_rect.left = pos.x;
    m_rect.top = pos.y - 87;
    m_rect.width = m_texture.getSize().x;
    m_rect.height = m_texture.getSize().y - 97;

    m_sprite.setPosition(m_position);
}

Tree1::~Tree1()
{
    //dtor
}
