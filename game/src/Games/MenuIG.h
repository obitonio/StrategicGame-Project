#ifndef MENUIG_H
#define MENUIG_H

#include "../Main.hpp"
#include "../Drawable.h"
#include "Order.h"

class MenuIG
{
    public:
        MenuIG(Drawable *drawable, int team);

        void update(sf::RenderWindow &window, Order &order);

        void draw (sf::RenderWindow &window);

        void init(sf::Vector2i resolution);

        void setID(int id);

        void setDrawable(Drawable* drawable);

        virtual ~MenuIG();
    protected:
    private:
        Drawable *m_drawable;

        sf::View m_view;
        sf::RectangleShape m_rect;
        sf::Texture m_textureBuilding, m_textureUnits[8];
        sf::Sprite m_spriteBuilding, m_spriteUnit;

        sf::Vector2i m_posBuild;

        sf::Clock m_unitClock, m_unlockClock;

        int m_id, m_totalUnits, m_team;
        int *m_unitsList;
        int m_unitType[8];
};

#endif // MENUIG_H
