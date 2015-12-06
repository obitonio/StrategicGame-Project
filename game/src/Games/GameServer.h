#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "../Main.hpp"
#include "World.h"
#include "EventManager.h"
#include "Order.h"

class GameServer
{
    public:
        GameServer(sf::TcpSocket &socket);

        void update(sf::RenderWindow &window, sf::TcpSocket &socket);

        void draw(sf::RenderWindow &window);

        virtual ~GameServer();
    protected:
    private:
        //GAME
        EventManager m_eventManager;
        World m_world;
        Order m_order;

        int m_team; // 1
};

#endif // GAMESERVER_H
