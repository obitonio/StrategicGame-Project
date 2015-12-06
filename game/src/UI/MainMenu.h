#ifndef MAINMENU_H
#define MAINMENU_H

#include "../Main.hpp"

#include "../Tools.hpp"

class MainMenu
{
    public:
        MainMenu();

        void update (sf::RenderWindow &window, int &state);

        void draw (sf::RenderWindow &window);

        virtual ~MainMenu();
    protected:
    private:
        sf::Texture m_textureBackground, m_textureLogo;
        sf::Sprite m_spriteBackground, m_spriteLogo;

        Button m_buttonSolo, m_buttonMulti;
};

#endif // MAINMENU_H
