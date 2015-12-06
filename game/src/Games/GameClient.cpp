#include "GameClient.h"

GameClient::GameClient(sf::TcpSocket &socket)
:m_eventManager(), m_team(2), m_world(2), m_order(m_world, socket)

{
    //ctor
}


void GameClient::update(sf::RenderWindow &window, sf::TcpSocket &socket)
{
    sf::Packet packet;
    if (socket.receive(packet));
    {
        int id = -1;
        packet >> id;
        switch (id)
        {
        case 1:
            m_world.update(packet);
            break;
        default:
            break;
        }
    }



    m_eventManager.updateClient(window, m_world, m_order, m_team);
}

void GameClient::draw(sf::RenderWindow &window)
{
    m_world.draw(window, m_team, m_order);
    m_eventManager.draw(window); // Selection RectangleShape
}

GameClient::~GameClient()
{
    //dtor
}
