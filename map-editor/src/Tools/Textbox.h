#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "../Main.h"
#include <sstream>

class Textbox
{
    public:
        Textbox(sf::Vector2f position, sf::String defaultStr, int sizeX = 150, int sizeY = 30, int maxChar=10);

        void update(sf::RenderWindow &window, sf::Event &event);

        void draw(sf::RenderWindow &window);

        sf::String getText();

        short getShort();

        virtual ~Textbox();
    protected:
    private:
        sf::Vector2f m_position, m_size;
        sf::String m_str, m_defaultStr;
        sf::Font m_font;
        sf::Text m_text;

        sf::Clock m_clock;

        int m_maxChar;
        bool m_isLock, m_keyPressed;
};

#endif // TEXTBOX_H
