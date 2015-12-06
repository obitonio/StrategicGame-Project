#ifndef LABEL_H
#define LABEL_H

#include "../Main.hpp"

class Label
{
    public:
        Label(sf::Vector2f position, sf::String str, int sizeChar = 30);

        void draw(sf::RenderWindow &window);

        void setString(sf::String str);

        virtual ~Label();
    protected:
    private:
        sf::Font m_font;
        sf::Text m_text;
        sf::Vector2f m_position;
};

#endif // LABEL_H
