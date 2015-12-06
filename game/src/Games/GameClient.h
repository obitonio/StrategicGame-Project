#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include "../Main.hpp"
#include "World.h"
#include "EventManager.h"
#include "Order.h"

class GameClient
{
    public:
        GameClient(sf::TcpSocket &socket);

        void update(sf::RenderWindow &window, sf::TcpSocket &socket);

        void draw(sf::RenderWindow &window);

        virtual ~GameClient();
    protected:
    private:
        //GAME
        EventManager m_eventManager;
        World m_world;
        Order m_order;

        int m_team; //2
};

#endif // GAMECLIENT_H
