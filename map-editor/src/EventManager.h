#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Main.h"

#include "Map.h"
#include "ItemSelector.h"
#include "ItemSelectorIn.h"

class EventManager
{
    public:
        EventManager();

        void update(sf::RenderWindow &window, Map &map, ItemSelector &itemSelector, ItemSelectorIn &itemSelectorIn, bool &screenmode, bool &showMinimap);

        virtual ~EventManager();
    protected:
    private:
        sf::Vector2i m_moove;
        int m_items[MAX_OBJ], m_units[200];
        int m_index, m_indexResolution;

        sf::Clock m_clockM, m_clockR;
};

#endif // EVENTMANAGER_H
