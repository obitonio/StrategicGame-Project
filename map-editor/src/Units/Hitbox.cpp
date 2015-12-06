#include "Hitbox.h"

Hitbox::Hitbox()
:m_position(sf::Vector2i(0, 0)), m_rect(0, 0, 0, 0), m_visible(false), m_width(0), m_height(0)
{
    //ctor
}

Hitbox::Hitbox(sf::Vector2i position, int width, int height)
:m_position(position), m_rect(m_position.x, m_position.y, width, height),
m_visible(true), m_width(width), m_height(height), m_rectShape(sf::Vector2f(width, height))
{
    m_rectShape.setOutlineColor(sf::Color::Red);
    m_rectShape.setOutlineThickness(5);
    m_rectShape.setPosition(m_position.x, m_position.y);
    m_rectShape.setFillColor(sf::Color::Transparent);
}

void Hitbox::init(sf::Vector2i position, int width, int height)
{
    m_position = position;

    m_rectShape.setOutlineColor(sf::Color::Red);
    m_rectShape.setOutlineThickness(1);
    m_rectShape.setPosition(m_position.x, m_position.y);
    m_rectShape.setSize(sf::Vector2f(width, height));
    m_rectShape.setFillColor(sf::Color::Transparent);

    m_visible = true;
}

void Hitbox::setPosition(sf::Vector2i position)
{
    m_position = position;

    m_rectShape.setPosition(m_position.x, m_position.y);
}

void Hitbox::draw(sf::RenderWindow &window)
{
    if (m_visible)
        window.draw(m_rectShape);
}

void Hitbox::setVisible(bool visible)
{
    m_visible = visible;
}

Hitbox::~Hitbox()
{
    //dtor
}
