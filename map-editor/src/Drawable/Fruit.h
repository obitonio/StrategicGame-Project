#ifndef FRUIT_H
#define FRUIT_H

#include "Drawable.h"

class Fruit : public Drawable
{
    public:
        Fruit(sf::Vector2i pos);
        virtual ~Fruit();
    protected:
    private:
};

#endif // FRUIT_H
