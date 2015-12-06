#include "Drawable.h"

Drawable::Drawable()
:m_rect(0, 0, 0, 0), m_type(0), m_isfocus(0), m_isFloor(false), m_team(-1),
 m_defaultlife(1000), m_life(m_defaultlife), m_imgLink("null"), m_ID(-1)
{
    for (int i=0; i<=8; i++)
    {
        m_unitsList[i] = 0;
    }
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

        if (m_team != -1)
        {
            sf::RectangleShape lifeRect(sf::Vector2f((m_texture.getSize().x * m_life)/m_defaultlife, 2));
            lifeRect.setPosition(m_position.x, m_position.y - 5);

            if (enemyTeam == m_team)
                lifeRect.setFillColor(sf::Color::Red);
            else
                lifeRect.setFillColor(sf::Color::Green);

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

sf::Vector2i Drawable::getPos()
{
    return m_pos;
}

sf::Vector2i Drawable::getSize()
{
    return sf::Vector2i(m_texture.getSize().x, m_texture.getSize().y);
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

 int* Drawable::getUnitsList()
{
    return m_unitsList;
}

int Drawable::getID()
{
    return m_ID;
}

void Drawable::setID(int id)
{
    m_ID = id;
}

 int Drawable::getTeam()
 {
     return m_team;
 }

 void Drawable::setTeam(int team)
{
    m_team = team;
}

std::string Drawable::getImgLink()
{
    return m_imgLink;
}

Drawable::~Drawable()
{
    //dtor
}
