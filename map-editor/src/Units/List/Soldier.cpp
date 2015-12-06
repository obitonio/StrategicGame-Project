#include "Soldier.h"

Soldier::Soldier(sf::Vector2i pos, int ID, int team)
:Unit(pos, ID, team)
{
    m_defaultlife = 100;
    m_life = m_defaultlife;
    m_damage = 25;
    m_rect.height = 30;
    m_rect.width = 30;

    // ==============RIGHT==============
    for (int i=0; i<6; i++)
    {
        m_rectTexture[i] = sf::IntRect(1+i*32, 1, 30, 28);
    }

    m_rectTexture[10] = sf::IntRect(0, 60, 23, 31);
    m_rectTexture[11] = sf::IntRect(26, 60, 21, 33);
    m_rectTexture[12] = sf::IntRect(48, 66, 41, 27);


    m_animation.setTexture("resource/texture.png");
    m_animation.setMaxFrame(6, 3);

    for (int i=0; i<6; i++)
        m_animation.setRectPosition(m_rectTexture[i], i, -1, true); // movement

    for (int i=0; i<3; i++)
        m_animation.setRectPosition(m_rectTexture[i+10], -1, i, true); // fight
    // =================================

    // ==============LEFT==============  y+100
    for (int i=6; i>0; i--)
    {
        m_rectTexture[i] = sf::IntRect(1+i*32, 1, 30, 28);
    }

    m_rectTexture[12] = sf::IntRect(0, 60, 23, 31);
    m_rectTexture[11] = sf::IntRect(26, 60, 21, 33);
    m_rectTexture[10] = sf::IntRect(48, 66, 41, 27);


    m_animation.setTexture("resource/texture.png");
    m_animation.setMaxFrame(6, 3);

    for (int i=0; i<6; i++)
        m_animation.setRectPosition(m_rectTexture[i], i, -1, false); // movement

    for (int i=0; i<3; i++)
        m_animation.setRectPosition(m_rectTexture[i+10], -1, i, false); // fight
    // =================================

    m_hitbox.init(sf::Vector2i(m_position.x, m_position.y), m_animation.getSize().x, m_animation.getSize().y);
}

Soldier::~Soldier()
{
    //dtor
}
