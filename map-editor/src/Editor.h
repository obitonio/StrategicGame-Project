#ifndef EDITOR_H
#define EDITOR_H

#include "Main.h"

#include "Map.h"
#include "ItemSelector.h"
#include "ItemSelectorIn.h"
#include "Order.h"
#include "EventManager.h"
#include "Minimap.h"

class Editor
{
    public:
        Editor();

        void update(sf::RenderWindow &window);

        void draw(sf::RenderWindow &window);

        virtual ~Editor();
    protected:
    private:
        Map m_map;
        ItemSelector m_itemSelector;
        ItemSelectorIn m_itemSelectorIn;
        Order m_order;
        EventManager m_eventManager;
        Minimap m_minimap;
        bool m_fullscreen, m_threadinit;

        //
        bool m_showMinimap;
        //

        sf::Thread m_threadSelector;
        sf::Thread m_threadOrder;
};

#endif // EDITOR_H
