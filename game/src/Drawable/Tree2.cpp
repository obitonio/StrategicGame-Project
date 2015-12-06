#include "Tree2.h"

Tree2::Tree2(sf::Vector2i pos)
:Drawable()
{
    m_type = 1;

    m_texture.loadFromFile("resource/map/arbre2.png");
    m_sprite.setTexture(m_texture);

    m_pos = pos;
    m_position = sf::Vector2f(pos.x - m_texture.getSize().x/2, pos.y - m_texture.getSize().y/2);
    m_positionCenter = sf::Vector2f(pos.x+m_texture.getSize().x/2, pos.y+m_texture.getSize().y/2);
    m_sprite.setPosition(m_position);

    int rx = m_texture.getSize().x/2;
    int ry =m_texture.getSize().y/2;

    m_rect.left = pos.x + rx;
    m_rect.top = pos.y - 87;
    m_rect.width = m_texture.getSize().x - rx;
    m_rect.height = m_texture.getSize().y - 97;
}

Tree2::~Tree2()
{
    //dtor
}
