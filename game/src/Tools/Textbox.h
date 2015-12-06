#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "../Main.hpp"
#include <sstream>

class Textbox
{
    public:
        Textbox(sf::Vector2f position, sf::String defaultStr, int sizeX = 150, int sizeY = 30, int maxChar=10);

        void update(sf::RenderWindow &window, sf::Event &event);

        void draw(sf::RenderWindow &window);

        sf::String getText();

        short getShort();

        void hideChar(bool hide);

        virtual ~Textbox();
    protected:
    private:
        sf::Vector2f m_position, m_size;
        sf::String m_str, m_defaultStr, m_hideStr;
        sf::Font m_font;
        sf::Text m_text;

        sf::Clock m_clock;

        int m_maxChar, m_strSize;
        bool m_isLock, m_keyPressed, m_hideChar;
};

#endif // TEXTBOX_H
