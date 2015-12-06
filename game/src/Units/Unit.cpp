#include "Unit.h"
#include "World.h"

Unit::Unit()
:m_position(-1, -1),
m_ID(-1), m_team(-1) , m_defaultlife(0), m_life(m_defaultlife), m_damage(25),
m_direction(0), m_distance(0), m_distanceReach(0),
m_positionTarget(-1, -1), m_targetID(-1), m_rangeUnit(false),
m_isLocked(false), m_hitbox(), m_animation("resource/texture.png", sf::Vector2i(m_position.x, m_position.y))
{

}

Unit::Unit(sf::Vector2i position, int ID, int team)
:m_position(position),
m_ID(ID), m_team(team) , m_defaultlife(100), m_life(m_defaultlife), m_damage(25),
m_direction(0), m_distance(0), m_distanceReach(0),
m_positionTarget(-1, -1), m_targetID(-1),
m_isLocked(false), m_hitbox(),
m_animation("resource/texture.png", position)
{

}
// FUNC

void Unit::update(sf::RenderWindow &window, Unit *unit, Drawable *drawable)
{
    m_animation.update();
    //std::cout << "ID: " << m_targetID << " posX: " << drawable[m_targetID].getPos().x << std::endl;
    if (m_targetID != -1)
    {
        if (!m_rangeUnit)
            this->updateContactUnit(window, unit, drawable);
        else
            this->updateRangeUnit(window, unit, drawable);
    }
    //std::cout << m_ID << " x: " << m_positionTarget.x << " y: " << m_positionTarget.y << std::endl;


    if (sf::Vector2i(m_positionTarget.x, m_positionTarget.y) == sf::Vector2i(m_position.x, m_position.y) ||
        m_distanceReach > m_distance)
    {
        m_positionTarget = sf::Vector2f(-1, -1);

        m_hitbox.init(sf::Vector2i(m_position.x,m_position.y), m_animation.getSize().x, m_animation.getSize().y);
        m_animation.setPosition(sf::Vector2i(m_position.x,m_position.y));
        m_animation.standing();
       // std::cout << "Target reached" << std::endl;
    }
    else if (m_positionTarget != sf::Vector2f(-1, -1))
    {
        bool canMoove = true;
        //===================COLLISION OBJET==================
       /* for (int i=0; i<MAX_OBJ; i++)
        {
            int range = 0;

            if (drawable[i].getPositionCenter().x > m_position.x)
                range = drawable[i].getPositionCenter().x - m_position.x;
            else
                range = m_position.x - drawable[i].getPositionCenter().x;
            std::cout << range << std::endl;
            if (range < 5 + drawable[i].getSize().x)
            {
                canMoove = false;
            }
        }*/

        //===================COLLISION UNITS==================
       /* for (int i=0; i<MAX_UNIT; i++)
        {
           if (m_position.x > unit[i].getPosition().x)
           {
               if (m_position.x < unit[i].getPosition().x + unit[i].getSize().x &&
                   m_position.y > unit[i].getPosition().y &&
                   m_position.y < unit[i].getPosition().y + unit[i].getSize().y)
               {
                   canMoove = false;
               }
           }
           else if (m_position.x < unit[i].getPosition().x)
           {
               if (m_position.x + m_animation.getSize().x > unit[i].getPosition().x &&
                   m_position.y > unit[i].getPosition().y &&
                   m_position.y < unit[i].getPosition().y + unit[i].getSize().y)
               {
                   canMoove = false;
               }
           }
        }*/

        //============= DEPLACEMENT=============
        if (canMoove)
        {
            m_position.y = m_equationAff.f(m_position.x);
            m_distanceReach++;

            //TODO Corriger bug vertical

            if (m_direction == 1)
            {
                m_position.x++;
                m_animation.nextRight();
            }
            else if (m_direction == 2)
            {
                    m_position.x--;
                    m_animation.nextLeft();
            }
        }
        else
        {
            if (m_direction == 1)
            {
                m_position.x--;
                m_animation.nextRight();
            }
            else if (m_direction == 2)
            {
                m_position.x++;
                m_animation.nextLeft();
            }
        }

        //=====================================

        m_hitbox.init(sf::Vector2i(m_position.x,m_position.y), m_animation.getSize().x, m_animation.getSize().y);
        m_animation.setPosition(sf::Vector2i(m_position.x,m_position.y));
    } //Centrer l'origine de l'image (What ?)
}

void Unit::updateContactUnit(sf::RenderWindow &window, Unit *unit, Drawable *drawable)
{
           // std::cout << m_positionTarget.x << " " << unit[m_targetID].getPosition().x << std::endl;

        if (m_positionTarget.x != unit[m_targetID].getPosition().x ||
            m_positionTarget.y != unit[m_targetID].getPosition().y)
            {
                m_positionTarget.x = int(m_positionTarget.x);
                m_positionTarget.y = int(m_positionTarget.y);
              /*  std::cout << "======" << std::endl;
                std::cout << "OldX: " << m_positionTarget.x << " OldY: " << m_positionTarget.y << " NewX: " << unit[m_targetID].getPosition().x << " NewY: " << unit[m_targetID].getPosition().y << std::endl;
                std::cout << "TargetID: " << m_targetID << std::endl;
                std::cout << "======" << std::endl;*/

                sf::Vector2i t1, t2;

                if (m_position.x > unit[m_targetID].getPosition().x)
                    t1 = sf::Vector2i(unit[m_targetID].getPosition().x + unit[m_targetID].getSize().x, unit[m_targetID].getPosition().y);
                else if (m_position.x < unit[m_targetID].getPosition().x)
                    t1 = sf::Vector2i(unit[m_targetID].getPosition().x, unit[m_targetID].getPosition().y);

                if (m_position.y > unit[m_targetID].getPosition().y)
                    t2 = sf::Vector2i(t1.x, unit[m_targetID].getPosition().y + unit[m_targetID].getSize().y);
                else if (m_position.y < unit[m_targetID].getPosition().y)
                    t2 = sf::Vector2i(t1.x, unit[m_targetID].getPosition().y);



                this->goTo(unit[m_targetID].getPosition().x, unit[m_targetID].getPosition().y, false);
            }
        int mx, my;
        if (m_position.x > unit[m_targetID].getPosition().x)
        {
            mx = m_position.x - unit[m_targetID].getPosition().x;
        }
        else if (unit[m_targetID].getPosition().x > m_position.x)
        {
            mx = unit[m_targetID].getPosition().x - m_position.x;
        }

        if (m_position.y > unit[m_targetID].getPosition().y)
        {
            my = m_position.y - unit[m_targetID].getPosition().y;
        }
        else if (unit[m_targetID].getPosition().y > m_position.y)
        {
            my = unit[m_targetID].getPosition().y - m_position.y;
        }

        if ((my+mx)/2 < 5 && m_couldnot.getElapsedTime().asSeconds() > 2)
        {
            unit[m_targetID].decreaseLife(m_damage);
            m_animation.fight();
            m_couldnot.restart();
        }
            // PAS NORMAL
}


void Unit::updateRangeUnit(sf::RenderWindow &window, Unit *unit, Drawable *drawable)
{
            if (m_targetID != -1)
            {
                std::cout << "range unit" << std::endl;
                for (int i= 0; i <2; i++)
                {
                    if (m_arrow[i].getTargetID() == -1)
                        m_arrow[i].setTargetID(m_targetID, m_positionCenter);

                    m_arrow[i].update(window, unit);
                }
            }
}


void Unit::draw(sf::RenderWindow &window, int enemyTeam)
{
    //std::cout << "Anim: " << m_animation.getSize().x << " life: " << m_life << " def: " << m_defaultlife << std::endl;
    sf::RectangleShape lifeRect(sf::Vector2f((m_animation.getSize().x * m_life)/m_defaultlife, 2));
    lifeRect.setPosition(m_position.x, m_position.y - 5);

    if (enemyTeam == m_team)
        lifeRect.setFillColor(sf::Color::Red);
    else
        lifeRect.setFillColor(sf::Color::Blue);

    if (m_isLocked)
        m_hitbox.draw(window);

    m_animation.draw(window);
    window.draw(lifeRect);

    for (int i= 0; i <2; i++)
    {
        if (m_arrow[i].getTargetID() != -1)
                m_arrow[i].draw(window);
    }
}

void Unit::goTo(sf::Vector2i position, bool resetTarget)
{
    if (resetTarget)
        m_targetID = -1; // Unlock

   // std::cout << "Unit::Goto: " << position.x << " y:" << position.y << std::endl;
    m_positionTarget = sf::Vector2f(position.x,position.y);
    m_equationAff = Equation(1, m_position, m_positionTarget);

    if (m_positionTarget.x > m_position.x) // To right
    {
        m_direction = 1;
        m_distance = m_positionTarget.x - m_position.x;
    }
    else if (m_positionTarget.x < m_position.x) // To left
    {
        m_direction = 2;
        m_distance = m_position.x - m_positionTarget.x;
    }
    m_distanceReach = 0;
}

void Unit::goTo(int x, int y, bool resetTarget)
{
    if (resetTarget)
        m_targetID = -1; // Unlock

    //std::cout << "Unit::Goto: " << x << " y:" << y << std::endl;
    m_positionTarget = sf::Vector2f(x, y);
    m_equationAff = Equation(1, m_position, m_positionTarget);

    if (m_positionTarget.x > m_position.x) // To right
    {
        m_direction = 1;
        m_distance = m_positionTarget.x - m_position.x;
    }
    else if (m_positionTarget.x < m_position.x) // To left
    {
        m_direction = 2;
        m_distance = m_position.x - m_positionTarget.x;
    }
    m_distanceReach = 0;
}

void Unit::decreaseLife(int damage)
{
    m_life -= damage;
}

void Unit::lock()
{
    m_isLocked = true;
}

void Unit::unlock()
{
    m_isLocked = false;
}

void Unit::setID(int ID)
{
    m_ID = ID;
}

void Unit::setTeam(int team)
{
    m_team = team;
}

void Unit::setPosition(sf::Vector2f position)
{
    m_position = position;
    m_animation.setPosition(sf::Vector2i(m_position.x,m_position.y));
}

void Unit::setPosition(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
    m_animation.setPosition(sf::Vector2i(m_position.x,m_position.y));
}

void Unit::setLife(int life)
{
    m_life = life;
}

void Unit::setTarget(Unit *target)
{
    m_targetID = target->getID();
}

void Unit::setTarget(int ID)
{
    std::cout << "New target: " << m_targetID << std::endl;
    m_targetID = ID;
}

void Unit::setAnimationIndex(int i)
{
    m_animation.setIndex(i);
}

// GET
int Unit::getID()
{
    return m_ID;
}

int Unit::getTeam()
{
    return m_team;
}

bool Unit::isRangeUnit()
{
    return m_rangeUnit;
}

sf::Vector2f Unit::getPosition()
{
    return m_position;
}

sf::Vector2f Unit::getPositionTarget()
{
    return m_positionTarget;
}

int Unit::getTargetID()
{
    return m_targetID;
}

int Unit::getLife()
{
    return m_life;
}

int Unit::getDefaultLife()
{
    return m_defaultlife;
}

sf::Vector2i Unit::getSize()
{
    return m_animation.getSize();
}

int Unit::getAnimationIndex()
{
    return m_animation.getIndex();
}

Animation& Unit::getAnimation()
{
    return m_animation;
}

int Animation::getDirection()
{
    return m_direction;
}

Unit::~Unit()
{
    delete m_rectTexture;
}
