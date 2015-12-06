#include "ItemSelectorIn.h"

ItemSelectorIn::ItemSelectorIn()
:m_size(50),
m_lockedID(-1)
{
    m_texture[0].loadFromFile("resource/map/arbre1m.png");
    m_texture[1].loadFromFile("resource/map/arbre2m.png");
    m_texture[2].loadFromFile("resource/map/arbre3m.png");
    m_texture[3].loadFromFile("resource/map/road1m.png");

    m_texture[4].loadFromFile("resource/map/buisson1m.png");
    m_texture[5].loadFromFile("resource/map/buisson2m.png");
    m_texture[6].loadFromFile("resource/map/buisson4m.png");
    m_texture[7].loadFromFile("resource/map/buisson5m.png");

    m_texture[12].loadFromFile("resource/map/barrack1m.png");
    m_texture[13].loadFromFile("resource/map/barrack2m.png");
    m_texture[14].loadFromFile("resource/map/barrack3m.png");
    m_texture[15].loadFromFile("resource/map/barrack4m.png");

    m_texture[16].loadFromFile("resource/map/fermem.png");
    m_texture[17].loadFromFile("resource/map/fruitm.png");
    m_texture[18].loadFromFile("resource/map/marchem.png");
    m_texture[19].loadFromFile("resource/map/millm.png");

    m_texture[20].loadFromFile("resource/map/house1m.png");
    m_texture[21].loadFromFile("resource/map/house2m.png");
    m_texture[22].loadFromFile("resource/map/house3m.png");
    m_texture[23].loadFromFile("resource/map/house4m.png");
    m_texture[24].loadFromFile("resource/map/house5m.png");
    m_texture[25].loadFromFile("resource/map/house6m.png");
    m_texture[26].loadFromFile("resource/map/house7m.png");
    m_texture[27].loadFromFile("resource/map/house8m.png");

    m_texture[28].loadFromFile("resource/map/churchm.png");

    m_texture[32].loadFromFile("resource/map/unit1.png");
    m_texture[33].loadFromFile("resource/map/unit2.png");

    m_view.setViewport(sf::FloatRect(0, 0, 0.5f, 1));
    //ctor
}

void ItemSelectorIn::update (sf::RenderWindow &window, sf::Vector2i resolution)
{
    if (window.hasFocus())
    {
        m_size = 32;

        sf::Vector2f pos(0, 0);
        for (int i=0; i<64; i++)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                sf::Mouse::getPosition(window).x > pos.x &&
                sf::Mouse::getPosition(window).x < pos.x + m_size &&
                sf::Mouse::getPosition(window).y > pos.y &&
                sf::Mouse::getPosition(window).y < pos.y + m_size)
            {
                m_lockedID = i;
            }

            if (pos.x == m_view.getSize().x)
            {
                pos.x = 0;
                pos.y += m_view.getSize().x/4;
            }
            else
                pos.x+=m_view.getSize().x/4;
        }
    }
}

void ItemSelectorIn::draw (sf::RenderWindow &window, sf::Vector2i resolution)
{
    window.setView(m_view);
    sf::Vector2f pos(0, 0);
    for (int i=0;i<64;i++)
    {
        m_sprite.setTexture(m_texture[i]);
        m_sprite.setPosition(pos);
        window.draw(m_sprite);

        if (pos.x == 3*m_size)
        {
            pos.x = 0;
            pos.y += m_size;
        }
        else
            pos.x+=m_size;
    }
}

int ItemSelectorIn::getLockedID()
{
    return m_lockedID;
}

ItemSelectorIn::~ItemSelectorIn()
{
    //dtor
}
