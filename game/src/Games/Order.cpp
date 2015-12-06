#include "Order.h"
#include "World.h"

Order::Order(World &world, sf::TcpSocket &socket)
: m_world(world), m_socket(socket)
{
    //ctor
}

void Order::send(int orderID, int ID, sf::Vector2f position)
{
    sf::Packet packet;
    packet << 2; // ID
    packet << orderID << ID << int(position.x) << int(position.y);
    m_socket.send(packet);
}

void Order::receive(sf::Packet &packet)
{
    int orderID, ID, posX, posY;
    packet >> orderID >> ID >> posX >> posY;

    switch (orderID)
    {
    case -1:
        m_world.getUnit(ID).goTo(posX, posY);
        break;  // Moove
    case 1:
        m_world.addUnit(posX, posY, 2, ID); // ClientTeam =2;
    default:
        m_world.getUnit(ID).setTarget(orderID);
        break;
    }

}

void Order::apply(int orderID, int ID, sf::Vector2f position)
{
    switch (orderID)
    {
    case -1:
        //std::cout << "ID: " << ID << " x: " << position.x << " y: "<< position.y << std::endl;
        m_world.getUnit(ID).goTo(position.x, position.y);
        break;  // Moove
    case 1:
        m_world.addUnit(position.x, position.y, 1, ID); // ServerTeam = 1
        break;
    default:
        m_world.getUnit(ID).setTarget(orderID);
        break;
    }
}

void Order::apply(int ID, int TID)
{
    m_world.getUnit(ID).setTarget(TID);
}

Order::~Order()
{
    //dtor
}
