#include "World.h"

World::World(int team)
:m_map(), m_minimap(m_map),
m_team(team), m_menuIG(m_map.getDrawable(), team)
{
    m_textureUnit.loadFromFile("resource/texture.png");
    m_textureUnit2.loadFromFile("resource/texture2.png");

    int ID = 0;
    for (int i=0; i<MAX_TEAMUNIT; i++)
    {
        m_unit[i] = Unit();
        m_unit[i].setID(ID);
        ID++;
    }
    for (int i=MAX_TEAMUNIT; i<MAX_TEAMUNIT*2; i++)
    {
        m_unit[i] = Unit();
        m_unit[i].setID(ID);
        ID++;
    }
    m_unit[0] = Soldier(sf::Vector2i(150, 50), 0, 1);
    m_unit[1] = Soldier(sf::Vector2i(150, 100), 1, 1);
    m_unit[2] = Bowman(sf::Vector2i(150, 150), 2, 1);

    m_unit[3] = Soldier(sf::Vector2i(250, 50), 3, 2);
    m_unit[4] = Soldier(sf::Vector2i(250, 100), 4, 2);
    m_unit[5] = Soldier(sf::Vector2i(250, 150), 5, 2);
    //Unit(m_textureUnit2, 1, 250, 50, 29, 33); // Dimension soldat occ
}

void World::updateUnit(sf::RenderWindow &window)
{
    for (int i=0; i<MAX_UNIT; i++)
    {
        if (m_unit[i].getLife() > 0)
            m_unit[i].update(window, m_unit, m_map.getDrawable());
    }
}

void World::draw(sf::RenderWindow &window, int team, Order &order)
{
    int enemyTeam;
    (team==1) ? enemyTeam = 2: enemyTeam = 1;

    m_minimap.update(m_map);
    m_menuIG.init(m_map.getResolution());
    m_menuIG.update(window, order);

    m_map.draw(window, enemyTeam);


    for (int i=0; i<MAX_UNIT; i++)
    {
        if (m_unit[i].getLife() > 0)
            m_unit[i].draw(window, enemyTeam);
    }

    m_minimap.draw(window);
    m_menuIG.draw(window);
}

void World::addUnit(int x, int y, int team, int type)
{
    int i;
    for (i=0; i<MAX_UNIT; i++)
    {
        if (m_unit[i].getLife() <=0)
        {
            break;
        }
    }

    switch (type)
    {
    case 1:
        m_unit[i] = Soldier(sf::Vector2i(x, y), i, team);
        std::cout << "ID " << i << " x: " << x << " y: " << y << " team: "<<team << std::endl;
        break;
    default:
        std::cout << "Unknow unit type !" << std::endl;
        break;
    }
}

int World::getUnit(int x, int y, int team)
{
    for (int i=0; i<MAX_UNIT; i++)
    {
        if (x > m_unit[i].getPosition().x &&
            x < m_unit[i].getPosition().x + m_unit[i].getSize().x &&
            y > m_unit[i].getPosition().y &&
            y < m_unit[i].getPosition().y + m_unit[i].getSize().y &&
            m_unit[i].getTeam() == team)
        {
            return i;
        }
    }
    return -1;
}

std::vector<int> World::getUnit(sf::Vector2f posA, sf::Vector2f posB, int team)
{
 //   posA = posA + m_view.getCenter();
   // posB = posB + m_view.getCenter();

    std::vector<int> id;
    int a = 0;
    if (posA.x < posB.x &&
        posA.y < posB.y)
    {
        for (int i=0; i<MAX_TEAMUNIT; i++)
        {
            if (m_unit[i].getPosition().x > posA.x &&
                m_unit[i].getPosition().x < posB.x &&
                m_unit[i].getPosition().y > posA.y &&
                m_unit[i].getPosition().x < posB.y &&
                m_unit[i].getTeam() == team)
            {
                id.push_back(i);
                a++;
            }
        }
    }
    else if (posA.x > posB.x &&
             posA.y > posB.y)
    {
        for (int i=0; i<MAX_TEAMUNIT; i++)
        {
            if (m_unit[i].getPosition().x < posA.x &&
                m_unit[i].getPosition().x > posB.x &&
                m_unit[i].getPosition().y < posA.y &&
                m_unit[i].getPosition().x > posB.y &&
                m_unit[i].getTeam() == team)
            {
                id.push_back(i);
                a++;
            }
        }
    }
    else if (posA.x > posB.x &&
             posA.y < posB.y)
    {
        for (int i=0; i<MAX_TEAMUNIT; i++)
        {
            if (m_unit[i].getPosition().x < posA.x &&
                m_unit[i].getPosition().x > posB.x &&
                m_unit[i].getPosition().y > posA.y &&
                m_unit[i].getPosition().x < posB.y &&
                m_unit[i].getTeam() == team)
            {
                id.push_back(i);
                a++;
            }
        }
    }
    else if (posA.x < posB.x &&
             posA.y > posB.y)
    {
        for (int i=0; i<MAX_TEAMUNIT; i++)
        {
            if (m_unit[i].getPosition().x > posA.x &&
                m_unit[i].getPosition().x < posB.x &&
                m_unit[i].getPosition().y < posA.y &&
                m_unit[i].getPosition().x > posB.y &&
                m_unit[i].getTeam() == team)
            {
                id.push_back(i);
                a++;
            }
        }
    }

    return id;
}

Unit& World::getUnit(int ID)
{
    for (int i = 0; i < MAX_UNIT; i++)
    {
        if (m_unit[i].getID() == ID)
            return m_unit[i];
    }
}

Unit* World::getUnit()
{
    return m_unit;
}

void World::update(sf::Packet &packet)
{
    for (int i = 0; i < MAX_UNIT; i++)
    {
        packet >> m_unit[i];
        //std::cout << m_unit[i] << std::endl;
    }
}

void World::send(sf::TcpSocket &socket)
{
    sf::Packet p;
    p << 1; // ID
    for (int i = 0; i < MAX_UNIT; i++)
    {
        p << m_unit[i];
    }
    socket.send(p);
}

void World::scroll(int x, int y)
{
    m_map.moove(x, y);
}

sf::Vector2i World::getSize()
{
    return m_map.getSize();
}

Map& World::getMap()
{
    return m_map;
}

MenuIG& World::getMenuIG()
{
    return m_menuIG;
}

World::~World()
{

}
