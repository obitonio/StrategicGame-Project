#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "../Main.hpp"

#include "World.h"
#include "Order.h"

class EventManager
{
    public:
        EventManager();

        void updateClient(sf::RenderWindow &window, World &world, Order &order, int team);

        void updateServer(sf::RenderWindow &window, World &world, Order &order, int team);

        void draw(sf::RenderWindow &window);

        virtual ~EventManager();
    protected:
    private:
        int m_unitID[MAX_TEAMUNIT], m_indexResolution;
        sf::Vector2f m_positionA, m_positionB;
        sf::RectangleShape m_lockRect;
        sf::Vector2i m_moove;
};

#endif // EVENTMANAGER_H
