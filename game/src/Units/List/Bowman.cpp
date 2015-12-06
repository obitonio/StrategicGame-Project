#include "Bowman.h"

Bowman::Bowman(sf::Vector2i pos, int ID, int team)
:Unit(pos, ID, team)
{
    m_rangeUnit = true;

    m_type = 3;
    m_defaultlife = 100;
    m_life = m_defaultlife;
    m_damage = 25;
    m_rect.height = 30;
    m_rect.width = 30;

    // ==============RIGHT==============
    for (int i=0; i<6; i++)
    {
        m_rectTexture[i] = sf::IntRect(i*24, 0, 24, 27);
    }

    m_rectTexture[10] = sf::IntRect(0, 60, 36, 27);
    m_rectTexture[11] = sf::IntRect(36, 60, 26, 28);
    m_rectTexture[12] = sf::IntRect(72, 60, 24, 27);


    m_animation.setTexture("resource/bowman.png");
    m_animation.setMaxFrame(6, 3);

    for (int i=0; i<6; i++)
        m_animation.setRectPosition(m_rectTexture[i], i, -1, true); // movement

    for (int i=0; i<3; i++)
        m_animation.setRectPosition(m_rectTexture[i+10], -1, i, true); // fight
    // =================================

    // ==============LEFT==============  y+100
    for (int i=6; i>0; i--)
    {
        m_rectTexture[i] = sf::IntRect(i*24, 100, 24, 27);
    }

    m_rectTexture[10] = sf::IntRect(50, 160, 36, 27);
    m_rectTexture[11] = sf::IntRect(24, 160, 26, 28);
    m_rectTexture[12] = sf::IntRect(0, 160, 24, 27);


    m_animation.setTexture("resource/bowman.png");
    m_animation.setMaxFrame(6, 3);

    for (int i=0; i<6; i++)
        m_animation.setRectPosition(m_rectTexture[i], i, -1, false); // movement

    for (int i=0; i<3; i++)
        m_animation.setRectPosition(m_rectTexture[i+10], -1, i, false); // fight
    // =================================

    m_hitbox.init(sf::Vector2i(m_position.x, m_position.y), m_animation.getSize().x, m_animation.getSize().y);
}

Bowman::~Bowman()
{
    //dtor
}
