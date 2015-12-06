#include "Label.h"

Label::Label(sf::Vector2f position, sf::String str, int sizeChar)
:m_text(str, m_font, sizeChar), m_position(position)
{
    m_font.loadFromFile("resource/comic.ttf");
    m_text.setPosition(m_position);
    m_text.setColor(sf::Color::Black);
}

void Label::draw(sf::RenderWindow &window)
{
    window.draw(m_text);
}

void Label::setString(sf::String str)
{
    m_text.setString(str);
}

Label::~Label()
{
    //dtor
}
