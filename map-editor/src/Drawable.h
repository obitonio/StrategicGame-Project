#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Main.h"

class Drawable
{
    public:

        Drawable();

        void update ();

        void draw (sf::RenderWindow &window, int enemyTeam);

        int getType();

        int getTeam();

        void setTeam(int team);

        void focus(bool foc);

        bool isFocus();

        virtual ~Drawable();

        sf::Vector2f getPosition();
        sf::Vector2f getPositionCenter();
        sf::Vector2i getPos();
        sf::Vector2i getSize();

        sf::IntRect getRect();

        bool isFloor();

    protected:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_position, m_positionCenter;
        sf::Vector2i m_pos;

        sf::IntRect m_rect;

        bool m_isfocus, m_isFloor, m_isNeutral;
        int m_type, m_team , m_defaultlife, m_life;
    private:
};

#endif // DRAWABLE_H
