#ifndef WORLD_H
#define WORLD_H

#include "../Main.hpp"
#include "../Units/Unit.h"
#include "../Units/List/Soldier.h"
#include "../Units/List/Bowman.h"

#include "Map.h"
#include "Minimap.h"
#include "MenuIG.h"
#include "Order.h"

#define NB_TEAM 2
#define MAX_TEAMUNIT 100
#define MAX_UNIT MAX_TEAMUNIT*NB_TEAM

#define MAPX 100
#define MAPY 100

class World
{
    public:
        World(int team);

        void updateUnit(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window, int team, Order &order);

        void addUnit(int x, int y, int team, int type);
        int getUnit(int x, int y, int team);

        std::vector<int> getUnit(sf::Vector2f posA, sf::Vector2f posB, int team);

        Unit& getUnit(int ID);
        Unit* getUnit();

        void update(sf::Packet &packet);

        void send(sf::TcpSocket &socket);

        void scroll(int x, int y);

        sf::Vector2i getSize();

        Map& getMap();
        MenuIG& getMenuIG();

        virtual ~World();
    protected:
    private:
        Unit m_unit[MAX_UNIT];
        sf::Texture m_textureUnit, m_textureUnit2;
        Map m_map;
        Minimap m_minimap;
        MenuIG m_menuIG;

        int m_team;

};

#endif // WORLD_H
