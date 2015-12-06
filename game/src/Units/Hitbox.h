#ifndef HITBOX_H
#define HITBOX_H

#include "../Main.hpp"
#include "../Drawable.h"

class Hitbox : public Drawable
{
    public:
        Hitbox();
        Hitbox(sf::Vector2i position, int width, int height);

        void init(sf::Vector2i position, int width, int height);

        void draw(sf::RenderWindow &window);

        void setPosition(sf::Vector2i position);

        void setVisible(bool visible);

        virtual ~Hitbox();
    protected:
    private:
        sf::Vector2i m_position;
        sf::IntRect m_rect;
        sf::RectangleShape m_rectShape;

        int m_width, m_height;
        bool m_visible;
};

#endif // HITBOX_H
