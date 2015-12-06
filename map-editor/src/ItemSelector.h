#ifndef ITEMSELECTOR_H
#define ITEMSELECTOR_H

#include "Main.h"

#include "Map.h"

class ItemSelector
{
    public:
        ItemSelector(Map &map);

        void update ();
        /*
            In need to be launched in a thread or the application will not work
        */

        void draw ();

        int getLockedID();

        virtual ~ItemSelector();
    protected:
    private:
        sf::RenderWindow m_window;
        sf::Texture m_texture[64];
        sf::Sprite m_sprite;

        Map &m_map;

        int m_size, m_lockedID;
};

#endif // ITEMSELECTOR_H
