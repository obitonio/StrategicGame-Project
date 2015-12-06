#include "EventManager.h"

EventManager::EventManager()
:m_positionA(-1, -1), m_positionB(-1, -1), m_moove(0, 0), m_indexResolution(4)
{
    m_lockRect.setFillColor(sf::Color::Transparent);
    m_lockRect.setOutlineColor(sf::Color::Green);
    m_lockRect.setOutlineThickness(2);

    for (int i = 0; i < MAX_TEAMUNIT; i++)
    {
        m_unitID[i] = -1;
    }
}

void EventManager::updateClient(sf::RenderWindow &window, World &world, Order &order, int team)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus())
    {
        if (world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, team) != -1) // Team = 2
            m_unitID[0] = world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, team);
        else if(world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID() != 0  &&
               world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getTeam() == team)
        {
            std::cout << "ID" <<world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID() << std::endl;
            world.getMenuIG().setID(world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID());
        }
        else
        {
            std::cout << "Nothing here" << std::endl;
            for (int i = 0; m_unitID[i] != -1; i++)
            {
                m_unitID[i] = -1;
            }
        }

        if (m_positionA == sf::Vector2f(-1, -1))
            m_positionA = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        m_positionB = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
       // std::cout << m_positionA.x << " y: " << m_positionA.y << std::endl;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && window.hasFocus())
    {
        if (world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1) != -1) // enemyTeam = 1
        {
                for (int i = 0; m_unitID[i] != -1; i++)
                    order.send(world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 1), m_unitID[i], sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
        }
        else
        {
                for (int i = 0; m_unitID[i] != -1; i++)
                    order.send(-1, m_unitID[i], sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_moove.y-50 > -50)
    {
        world.scroll(0, -50);
        m_moove.y -= 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_moove.y+50 <= world.getSize().y-1550) // BASE RESCTANGULAIRE
    {
        world.scroll(0, 50);
        m_moove.y += 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_moove.x+50 <= world.getSize().x-1000)
    {
        world.scroll(50, 0);
        m_moove.x += 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_moove.x-50 > -50)
    {
        world.scroll(-50, 0);
        m_moove.x -= 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
    {
        //int screenmode = world.getMap().getScreenMode();
        world.getMap().fullScreen(window);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
    {
        if (m_indexResolution > 0)
            m_indexResolution--;

        world.getMap().changeResolution(m_indexResolution, window);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
    {
        if (m_indexResolution < 10)
            m_indexResolution++;

        world.getMap().changeResolution(m_indexResolution, window);
    }
    else
    {
        if (m_positionB != sf::Vector2f(-1, -1))
        {
            std::vector<int> id = world.getUnit(m_positionA, m_positionB, 2);
            for (int i=0; i<id.size(); i++)
            {
                m_unitID[i] = id[i];
            }

        }
        m_positionA = sf::Vector2f(-1, -1);
        m_positionB = sf::Vector2f(-1, -1);
    }
}

void EventManager::updateServer(sf::RenderWindow &window, World &world, Order &order, int team)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.hasFocus())
    {
        if (world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, team) != -1) // team = 1
            m_unitID[0] = world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, team);
       else if(world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID() != 0 &&
               world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getTeam() == team)
        {
            std::cout << "ID: "<<world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID() << std::endl;
            world.getMenuIG().setID(world.getMap().getItem(m_moove+sf::Mouse::getPosition(window)).getID());
        }
        else
        {
            for (int i = 0; m_unitID[i] != -1; i++)
            {
                m_unitID[i] = -1;
            }
        }

        if (m_positionA == sf::Vector2f(-1, -1))
            m_positionA = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

        m_positionB = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && window.hasFocus())
    {
        if (m_unitID[0] != -1)
        {
            if (world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 2) != -1) // enemyTeam = 2
            {
                for (int i = 0; m_unitID[i] != -1; i++){
                if (!world.getUnit(m_unitID[i]).isRangeUnit())
                    order.apply(world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 2), m_unitID[i], sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));

                order.apply(m_unitID[i] ,world.getUnit(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, 2));
            }}
            else
            {
                for (int i = 0; m_unitID[i] != -1; i++)
                    order.apply(-1, m_unitID[i], sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
            }
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_moove.y-50 > -50)
    {
        world.scroll(0, -50);
        m_moove.y -= 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_moove.y+50 <= world.getSize().y-1550) // BASE RESCTANGULAIRE
    {
        world.scroll(0, 50);
        m_moove.y += 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_moove.x+50 <= world.getSize().x-1000)
    {
        world.scroll(50, 0);
        m_moove.x += 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_moove.x-50 > -50)
    {
        world.scroll(-50, 0);
        m_moove.x -= 50;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
    {
        world.getMap().fullScreen(window);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
    {
        if (m_indexResolution > 0)
            m_indexResolution--;

        world.getMap().changeResolution(m_indexResolution, window);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6))
    {
        if (m_indexResolution < 10)
            m_indexResolution++;

        world.getMap().changeResolution(m_indexResolution, window);
    }
        else
    {
    if (m_positionB != sf::Vector2f(-1, -1))
        {
            std::vector<int> id = world.getUnit(m_positionA, m_positionB, 1);
            for (int i=0; i<id.size(); i++)
            {
                m_unitID[i] = id[i];
            }

        }
        m_positionA = sf::Vector2f(-1, -1);
        m_positionB = sf::Vector2f(-1, -1);
    }
}

void EventManager::draw(sf::RenderWindow &window)
{
    if (m_positionB != sf::Vector2f(-1, -1))
    {
        m_lockRect.setSize(sf::Vector2f(m_positionB.x - m_positionA.x, m_positionB.y - m_positionA.y));
        m_lockRect.setPosition(m_positionA);
       // std::cout << m_lockRect.getPosition().x << " y= " << m_positionA.y << std::endl;
        //std::cout << sf::Mouse::getPosition(window).x << " M_y= " << sf::Mouse::getPosition(window).y << std::endl;

        window.draw(m_lockRect);
    }
}

EventManager::~EventManager()
{
    //dtor
}
