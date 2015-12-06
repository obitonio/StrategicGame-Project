#ifndef MINIMAP_H
#define MINIMAP_H

#include "../Main.hpp"
#include "Map.h"

class Minimap // BASE RESCTANGULAIRE
{
    public:
        Minimap(Map &map);

        void update(Map &map);

        void draw(sf::RenderWindow &window);

        virtual ~Minimap();
    protected:
    private:
        sf::Vector2f m_coef, m_coefScroll, m_size;

        sf::Image m_image;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::RectangleShape m_rect, m_rectScroll;

        sf::Color m_dColor, m_blackColor;

        sf::View m_view;

        Drawable *m_drawable;
};

#endif // MINIMAP_H
