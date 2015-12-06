#include "GameServer.h"

GameServer::GameServer(sf::TcpSocket &socket)
:m_eventManager(), m_team(1), m_world(1), m_order(m_world, socket)
{

}

void GameServer::update(sf::RenderWindow &window, sf::TcpSocket &socket)
{
    sf::Packet packet;
    if (socket.receive(packet));
    {
        int id = -1;
        packet >> id;
        switch (id)
        {
        case 2:
            m_order.receive(packet);
            break;
        default:
            break;
        }
    }


    m_eventManager.updateServer(window, m_world, m_order, m_team);
    m_world.updateUnit(window);
    m_world.send(socket);
}

void GameServer::draw(sf::RenderWindow &window)
{
    m_world.draw(window, m_team, m_order);
    m_eventManager.draw(window); // Selection RectangleShape
}

GameServer::~GameServer()
{
    //dtor
}
