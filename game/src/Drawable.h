#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Main.hpp"

class Drawable
{
    public:
        /*      BASIC FUNCTIONS     */
        Drawable();

        void update ();

        void draw (sf::RenderWindow &window, int enemyTeam);

        int getType();

        void focus(bool foc);

        bool isFocus();

        sf::Vector2f getPosition();
        sf::Vector2f getPositionCenter();
        sf::Vector2i getPos();
        sf::Vector2i getSize();

        sf::IntRect getRect();

        bool isFloor();

        virtual ~Drawable();
        /*       EXTENDED FUNCTIONS    */

        int* getUnitsList();

        int getID();

        void setID(int id);

        int getTeam();

        void setTeam(int team);

        std::string getImgLink();

    protected:
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        sf::Vector2f m_position, m_positionCenter;
        sf::Vector2i m_pos;

        sf::IntRect m_rect;

        bool m_isfocus, m_isFloor;
        int m_type, m_team , m_defaultlife, m_life;
        int m_unitsList[8];
        int m_ID;
        std::string m_imgLink;
    private:
};

#endif // DRAWABLE_H
