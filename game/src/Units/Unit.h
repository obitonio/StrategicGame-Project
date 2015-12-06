#ifndef UNIT_H
#define UNIT_H

#include "../Main.hpp"
#include "../Drawable.h"

#include "Hitbox.h"
#include "Animation.h"
#include "../Tools.hpp"
#include "../Drawable.h"
#include "Arrow.h"

class Unit : public Drawable
{
    public:
        Unit();
        Unit(sf::Vector2i position, int ID, int team);

        void update(sf::RenderWindow &window, Unit *unit, Drawable *drawable);

        void updateContactUnit(sf::RenderWindow &window, Unit *unit, Drawable *drawable);

        void updateRangeUnit(sf::RenderWindow &window, Unit *unit, Drawable *drawable);

        void draw(sf::RenderWindow &window, int enemyTeam);

        void decreaseLife(int damage);

        void lock();

        void unlock();

        // SET
        void setID(int ID);

        void setTeam(int team);

        void setLife(int life);

        void setPosition(sf::Vector2f position);
        void setPosition(int x, int y);

        void goTo(sf::Vector2i position, bool resetTarget = true);
        void goTo(int x, int y, bool resetTarget = true);

        void setTarget(Unit *target);
        void setTarget(int ID);

        void setAnimationIndex(int i);
        //

        // GET
        int getID();

        int getTeam();

        int getLife();

        int getDefaultLife();

        sf::Vector2f getPosition();

        sf::Vector2f getPositionTarget();

        int getTargetID();

        int getAnimationIndex();

        Animation& getAnimation();

        bool isRangeUnit();
        //

        sf::Vector2i getSize();

        virtual ~Unit();
    protected:

        sf::Vector2f m_size;

        /* Attributs principaux */
        sf::Vector2f m_position;
        int m_ID, m_team, m_defaultlife, m_life, m_damage;
        sf::Texture m_texture;
        sf::IntRect m_rectTexture[16];
        /* */

         /* Attributs de mouvement */
        int m_direction, m_distance, m_distanceReach;
        Equation m_equationAff;
        /* */

        /* Attributs de la cible */
        sf::Vector2f m_positionTarget;
        int m_targetID;
        /* */

        Arrow m_arrow[2];
        Hitbox m_hitbox;
        Animation m_animation;


        bool m_isLocked; // SI Focus
        bool m_rangeUnit;

        sf::Clock m_couldnot; // Temps d'attente entre 2 attaques !
};


sf::Packet& operator<<(sf::Packet& packet, Unit& unit);
sf::Packet& operator>>(sf::Packet& packet, Unit& unit);
std::ostream &operator<<(std::ostream& flux, Unit& unit);

#endif // UNIT_H
