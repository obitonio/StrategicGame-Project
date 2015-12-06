#ifndef ANIMATION_H
#define ANIMATION_H

#include "../Main.h"
#include "../Drawable.h"

class Animation : public Drawable
{
    public:
        Animation(sf::String texturelink, sf::Vector2i position);

        void update();

        void draw(sf::RenderWindow &window);

        void setMaxFrame(int frame, int fightFrame);

        void next();
        void nextRight();
        void nextLeft();
        void standing();
        void fight();

        void setPosition(sf::Vector2i position);

        void setTexture(sf::String link);

        void setRectPosition(sf::IntRect rect, int i=-1, int ifight=-1, bool right = true);

        void setIndex(int i);

        sf::Vector2i getSize();

        int getIndex();

        void flip();

        void flipPosition();

        void setDirection(int direction);

        int getDirection();

        virtual ~Animation();
    protected:
    private:
        sf::Vector2i m_position;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Image m_img;

        sf::IntRect m_rectPosLeft[10], m_rectfightPosLeft[10], m_rectPosRight[10], m_rectfightPosRight[10];
        int m_direction; // -1 to left ; 1 to right
        int m_maxFrame, m_maxFrameFight;

        bool m_isFlip;

        int m_iTexture, m_iFight;

        sf::Clock m_clock;
};

#endif // ANIMATION_H
