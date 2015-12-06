#ifndef CONNECTMENU_H
#define CONNECTMENU_H

#include "../Main.hpp"
#include "../Tools.hpp"

#include <winsock.h>
#include <MYSQL/mysql.h>

class ConnectMenu
{
    public:
        ConnectMenu();

        void update(sf::RenderWindow &window, sf::Event &event, int& state);

        void draw(sf::RenderWindow &window);

        bool connect(sf::String mail, sf::String mdp);

        virtual ~ConnectMenu();
    protected:
    private:
        sf::Texture m_backgroundTexture, m_textureLogo;
        sf::Sprite m_backgroundSprite, m_spriteLogo;

        Label m_labelMail, m_labelMdp, m_labelInfo;
        Textbox m_textboxMail, m_textboxMdp;
        Button m_buttonConnect;
};

#endif // CONNECTMENU_H
