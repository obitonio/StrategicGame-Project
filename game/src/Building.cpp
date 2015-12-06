#include "Building.h"

Building::Building()
:m_ID(-1)
{

}

int* Building::getUnitsList()
{
    return m_unitsList;
}

int Building::getID()
{
    return m_ID;
}

void Building::setID(int id)
{
    m_ID = id;
}

Building::~Building()
{

}
