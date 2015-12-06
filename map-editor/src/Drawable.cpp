#include "Drawable.h"

Drawable::Drawable()
:m_rect(0, 0, 0, 0), m_type(0), m_isfocus(0), m_isFloor(false), m_team(-1),
 m_defaultlife(1000), m_life(m_defaultlife), m_isNeutral(false)
{
    //ctor
}

void Drawable::update ()
{

}

void Drawable::draw (sf::RenderWindow &window, int enemyTeam)
{
    m_sprite.setTexture(m_texture);
    if (m_sprite.getTexture())
    {
        window.draw(m_sprite);
        if (m_isfocus)
        {
            sf::RectangleShape rect(sf::Vector2f(m_texture.getSize().x, m_texture.getSize().y));
            rect.setOutlineColor(sf::Color::Red);
            rect.setOutlineThickness(2);
            rect.setPosition(m_position);
            rect.setFillColor(sf::Color::Transparent);
            window.draw(rect);
        }

        if (m_team != -1 && !m_isNeutral)
        {
            sf::RectangleShape lifeRect(sf::Vector2f((m_texture.getSize().x * m_life)/m_defaultlife, 2));
            lifeRect.setPosition(m_position.x, m_position.y - 5);

            if (enemyTeam == m_team)
                lifeRect.setFillColor(sf::Color::Red);
            else
                lifeRect.setFillColor(sf::Color::Blue);

            window.draw(lifeRect);
        }
    }
}

sf::Vector2f Drawable::getPosition()
{
    return m_position;
}

sf::Vector2f Drawable::getPositionCenter()
{
    return m_positionCenter;
}

sf::IntRect Drawable::getRect()
{
    return m_rect;
}

int Drawable::getType()
{
    return m_type;
}

 int Drawable::getTeam()
 {
     return m_team;
 }

sf::Vector2i Drawable::getPos()
{
    return m_pos;
}

sf::Vector2i Drawable::getSize()
{
    return sf::Vector2i(m_texture.getSize().x, m_texture.getSize().y);
}

void Drawable::setTeam(int team)
{
    m_team = team;
}

void Drawable::focus(bool foc)
{
   m_isfocus = foc;
}

bool Drawable::isFocus()
{
    return m_isfocus;
}

 bool Drawable::isFloor()
 {
    return m_isFloor;
 }

Drawable::~Drawable()
{
    //dtor
}
