#include "Main.hpp"
#include "Units/Unit.h"
#include "Units/List/Soldier.h"

sf::Packet& operator<<(sf::Packet& packet, Unit& unit)
{
    packet << unit.getType()
    <<unit.getID()
    << unit.getTeam()
    << unit.getLife()
    <<int(unit.getPosition().x)
    << int(unit.getPosition().y)
    << unit.getTargetID()
    << unit.getAnimationIndex()
    << unit.getAnimation().getDirection();

    return packet;
}
// WARNING: Do not try to extract in a var with >> if the packet is empty !
sf::Packet& operator >>(sf::Packet& packet, Unit& unit)
{
    int type, ID, team, life, posx, posy, IDa, IDt, animDirect;

    packet >> type >> ID >> team >> life >> posx >> posy >> IDt >> IDa >> animDirect;
    if (unit.getDefaultLife() == 0)
    {
        switch (type)
        {
        case 1:
            unit = Soldier(sf::Vector2i(posx, posy), ID, team);
            break;
        }
    }
    unit.setID(ID);
    unit.setTeam(team);
    unit.setLife(life);
    unit.setPosition(posx, posy);
    unit.setTarget(IDt);
    unit.setAnimationIndex(IDa);
    unit.getAnimation().setDirection(animDirect);

    return packet;
}

std::ostream &operator<<(std::ostream& flux, Unit& unit)
{
    flux << "ID: " << unit.getID() << " Team: " << unit.getTeam() << " Life: " << unit.getLife() <<
    " x: " << unit.getPosition().x << " y: " << unit.getPosition().y;
    return flux;
}
