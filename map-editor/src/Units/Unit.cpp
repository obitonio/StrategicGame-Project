#include "Unit.h"

Unit::Unit()
:m_position(-1, -1),
m_ID(-1), m_team(-1) , m_defaultlife(0), m_life(m_defaultlife), m_damage(25),
m_direction(0), m_distance(0), m_distanceReach(0),
m_positionTarget(-1, -1), m_targetID(-1),
m_isLocked(false), m_hitbox(), m_animation("resource/texture.png", sf::Vector2i(m_position.x, m_position.y))
{

}

Unit::Unit(sf::Vector2i position, int ID, int team)
:m_position(position),
m_ID(ID), m_team(team) , m_defaultlife(0), m_life(m_defaultlife), m_damage(25),
m_direction(0), m_distance(0), m_distanceReach(0),
m_positionTarget(-1, -1), m_targetID(-1),
m_isLocked(false), m_hitbox(),
m_animation("resource/texture.png", position)
{
    if (m_team == 1)
        m_enemyTeam = 2;
    else if (m_team == 2)
        m_enemyTeam = 2;
}
// FUNC

void Unit::draw(sf::RenderWindow &window)
{
    sf::RectangleShape lifeRect(sf::Vector2f((m_animation.getSize().x * m_life)/m_defaultlife, 2));
    lifeRect.setPosition(m_position.x, m_position.y - 5);

    if (m_enemyTeam == m_team)
        lifeRect.setFillColor(sf::Color::Red);
    else
        lifeRect.setFillColor(sf::Color::Blue);

    if (m_isLocked)
        m_hitbox.draw(window);

    m_animation.draw(window);
    window.draw(lifeRect);
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
