#ifndef ITEMSELECTORIN_H
#define ITEMSELECTORIN_H

#include "Main.h"

#include "Map.h"

class ItemSelectorIn
{
    public:
        ItemSelectorIn();

        void update (sf::RenderWindow &window, sf::Vector2i resolution);

        void draw (sf::RenderWindow &window, sf::Vector2i resolution);

        int getLockedID();

        virtual ~ItemSelectorIn();
    protected:
    private:

        sf::Texture m_texture[64];
        sf::Sprite m_sprite;
        sf::View m_view;

        int m_size, m_lockedID;
};

#endif // ITEMSELECTORIN_H
