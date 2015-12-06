#ifndef ARROW_H
#define ARROW_H

#include "../Main.hpp"

#include "../Tools/Equation.h"

class Unit;

class Arrow
{
    public:
        Arrow();

        void update (sf::RenderWindow &window, Unit *unit);

        void draw (sf::RenderWindow &window);

        void setTargetID(int tid, sf::Vector2f position);

        int getTargetID();

        virtual ~Arrow();
    protected:
    private:
        int m_targetId;

        sf::Texture m_texture;
        sf::Sprite m_sprite;

        sf::Vector2f m_position;

        Equation m_equation;
};

#endif // ARROW_H
