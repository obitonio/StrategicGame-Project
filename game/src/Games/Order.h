#ifndef ORDER_H
#define ORDER_H

#include "../Main.hpp"

class World;

class Order
{
    public:
        Order(World &world, sf::TcpSocket &socket);

        void send(int orderID, int ID, sf::Vector2f position);

        void receive(sf::Packet &packet);

        void apply(int orderID, int ID, sf::Vector2f position);

        void apply(int ID, int TID);

        virtual ~Order();
    protected:
    private:
        World &m_world;
        sf::TcpSocket &m_socket;
};

#endif // ORDER_H
