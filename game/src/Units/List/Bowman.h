#ifndef BOWMAN_H
#define BOWMAN_H

#include "../Unit.h"

class Bowman : public Unit
{
    public:
        Bowman(sf::Vector2i pos, int ID, int team);
        virtual ~Bowman();
    protected:
    private:
};

#endif // BOWMAN_H
