#ifndef BUILDING_H
#define BUILDING_H

#include "../Main.hpp"
#include "Drawable.h"

class Building : public Drawable
{
    public:
        Building();

        int* getUnitsList();

        int getID();

        void setID(int id);

        virtual ~Building();
    protected:
        int m_unitsList[8];
        int m_ID;
    private:
};

#endif // BUILDING_H
