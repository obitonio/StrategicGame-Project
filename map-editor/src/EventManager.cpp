#include "EventManager.h"

EventManager::EventManager()
:m_moove(0, 0), m_index(0), m_indexResolution(4)
{
    for (int i=0; i<MAX_OBJ; i++)
    {
        m_items[i] = -1;
    }
    for (int i=0; i<200; i++)
    {
        m_units[i] = -1;
    }
}

void EventManager::update(sf::RenderWindow &window, Map &map, ItemSelector &itemSelector, ItemSelectorIn &itemSelectorIn, bool &screenmode, bool &showMinimap)
{
    if (window.hasFocus())
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && itemSelector.getLockedID() != -1
            && m_clockR.getElapsedTime().asSeconds() > 0.4 ||
            sf::Mouse::isButtonPressed(sf::Mouse::Right) && itemSelectorIn.getLockedID() != -1
            && m_clockR.getElapsedTime().asSeconds() > 0.4)
        {
            if (!screenmode)
                map.addItem(itemSelector.getLockedID(), m_moove + sf::Mouse::getPosition(window));
            else
                map.addItem(itemSelectorIn.getLockedID(), m_moove + sf::Mouse::getPosition(window));

            m_clockR.restart();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            int i=0;
            while (m_items[i] != -1 && i<MAX_OBJ)
            {
                i++;
            }

           // if (map.getItem(m_moove + sf::Mouse::getPosition(window)).getType() == 3)
            map.selectItem(m_moove + sf::Mouse::getPosition(window), m_items, m_index);
            bool a = true;
            for (i=0; m_units[i] != -1; i++)
            {
                if (m_units[i] == map.getUnit(m_moove + sf::Mouse::getPosition(window)))
                {
                    a = false;
                    m_units[i] = -1;
                }
            }

            m_units[i] = map.getUnit(m_moove + sf::Mouse::getPosition(window));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete))
        {
            for (int i=0; i<MAX_OBJ; i++)
            {
                if (m_items[i] != -1)
                {
                    map.removeItem(m_items[i]);
                }
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_moove.y-50 > -50)
        {
            map.moove(0, -50);
            m_moove.y -= 50;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_moove.y+50 <= map.getSize().y-1550) // BASE RESCTANGULAIRE
        {
            map.moove(0, 50);
            m_moove.y += 50;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_moove.x+50 <= map.getSize().x-1000)
        {
            map.moove(50, 0);
            m_moove.x += 50;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_moove.x-50 > -50)
        {
            map.moove(-50, 0);

            m_moove.x -= 50;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
        {
            map.fullScreen(window);
            if (screenmode)
                screenmode = false;
            else
                screenmode = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
        {
            if (m_indexResolution > 0)
                m_indexResolution--;

            map.changeResolution(m_indexResolution, window);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
        {
            if (m_indexResolution < 10)
                m_indexResolution++;

             map.changeResolution(m_indexResolution, window);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8))
        {
            map.changeTeam();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9))
        {
            map.hideLabel();
            (showMinimap) ? showMinimap=false : showMinimap=true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && m_clockM.getElapsedTime().asSeconds() > 0.5)
        {
            for (int i=0; i < 200; i++)
            {
                if (m_units[i] != -1)
                    map.flipUnit(m_units[i]);
            }
            m_clockM.restart();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            for (int i=0; i < 200; i++)
            {
                if (m_units[i] != -1)
                {
                    map.removeUnit(m_units[i]);
                    m_units[i] =  -1;
                }
            }
        }
    }
    /*system("cls");
    std::cout << "Liste des id actifs: " << std::endl;
    for (int b=0; b<200; b++)
    {
        if (m_units[b] != -1)
            std::cout << "ID: " << m_units[b] << std::endl;
    }*/
}

EventManager::~EventManager()
{
    //dtor
}
