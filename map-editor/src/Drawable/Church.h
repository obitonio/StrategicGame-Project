#ifndef CHURCH_H
#define CHURCH_H

#include "Drawable.h"

class Church : public Drawable
{
    public:
        Church(sf::Vector2i pos);
        virtual ~Church();
    protected:
    private:
};

#endif // CHURCH_H
