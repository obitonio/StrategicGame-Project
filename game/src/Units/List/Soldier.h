#ifndef SOLDIER_H
#define SOLDIER_H

#include "../Unit.h"

class Soldier : public Unit
{
    public:
        Soldier(sf::Vector2i pos, int ID, int team);
        virtual ~Soldier();
    protected:
    private:
};

#endif // SOLDIER_H
