#include "Textbox.h"

Textbox::Textbox(sf::Vector2f position, sf::String defaultStr, int sizeX, int sizeY, int maxChar)
:m_position(position), m_font(), m_text(m_str, m_font, 20), m_str(defaultStr), m_defaultStr(defaultStr),
m_size(sizeX, sizeY),m_isLock(false), m_maxChar(maxChar), m_keyPressed(false), m_hideStr(), m_strSize(m_str.getSize())
{
    m_font.loadFromFile("resource/comic.ttf");
    m_text.setPosition(m_position.x+5, m_position.y);
    m_text.setColor(sf::Color::Black);
}

void Textbox::update(sf::RenderWindow &window, sf::Event &event)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        sf::Mouse::getPosition(window).x > m_position.x &&
        sf::Mouse::getPosition(window).x < m_position.x + m_size.x &&
        sf::Mouse::getPosition(window).y > m_position.y &&
        sf::Mouse::getPosition(window).y < m_position.y + m_size.y)
    {
        m_isLock = true;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x < m_position.x ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x > m_position.x + m_size.x ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).y < m_position.y ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).y > m_position.y + m_size.y)
    {
        m_isLock = false;
    }


    if (event.type == sf::Event::TextEntered && m_isLock && !m_keyPressed && m_clock.getElapsedTime().asSeconds() > 0.15)
    {
        if (event.text.unicode > 32 && event.text.unicode < 127)
        {
            if (m_str == m_defaultStr)
                m_str = "";

            if (m_str.getSize()+1 <= m_maxChar)
            {
                m_strSize++;
                m_str += static_cast<char>(event.text.unicode);
            }
        }
        else if (event.text.unicode == 8)
        {
            if (m_str == m_defaultStr)
            {
                m_str = "";
                m_strSize = 0;
            }
            else
            {
                int a = m_str.getSize()-1;

                if (a >= 0)
                {
                    m_str.erase(m_str.getSize()-1);
                    m_strSize--;
                }

            }
        }

        if (m_hideChar)
        {
            if (m_strSize == 0)
            {
                m_text.setString("");
            }
            else
            {
                m_hideStr = "";
                for (int i=0; i<m_strSize; i++)
                {
                    m_hideStr += "*";
                    m_text.setString(m_hideStr);
                }
            }

        }
        else
            m_text.setString(m_str);

        m_clock.restart();
    }
    else if (!m_isLock && m_str.getSize() == 0)
    {
        m_str = m_defaultStr;
        m_text.setString(m_str);
    }
}

void Textbox::draw(sf::RenderWindow &window)
{
    sf::RectangleShape rect(m_size);
    rect.setPosition(m_position);
    rect.setOutlineThickness(1);
    if (m_isLock)
        rect.setOutlineColor(sf::Color::Cyan);
    else
        rect.setOutlineColor(sf::Color::Black);

    window.draw(rect);
    window.draw(m_text);
}

sf::String Textbox::getText()
{
    return m_str;
}

void Textbox::hideChar(bool hide)
{
    m_hideChar = hide;



    m_hideStr = "";
    for (int i=0; i<m_strSize; i++)
    {
        m_hideStr += "*";
        m_text.setString(m_hideStr);
    }
}

short Textbox::getShort()
{
    std::string str(m_str);
    std::stringstream ss(str);
    short s;
    ss >>s;
    return s;
}

Textbox::~Textbox()
{
    //dtor
}
