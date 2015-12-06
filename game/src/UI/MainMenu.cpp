#include "MainMenu.h"

MainMenu::MainMenu()
: m_buttonSolo("resource/Menu/solo.png", "resource/Menu/solo2.png", sf::Vector2f(300, 300)),
m_buttonMulti("resource/Menu/multi.png", "resource/Menu/multi2.png", sf::Vector2f(300, 400))
{
    m_textureBackground.loadFromFile("resource/Menu/backgroundMainMenu.jpg");
    m_spriteBackground.setTexture(m_textureBackground);
    m_spriteBackground.setPosition(0, 0);

    m_textureLogo.loadFromFile("resource/Menu/logo_AOE.png");
    m_spriteLogo.setTexture(m_textureLogo);
    m_spriteLogo.setPosition(200, 0);
}

void MainMenu::update (sf::RenderWindow &window, int &state)
{
    if (m_buttonMulti.mouseReleased(window))
        state = 2;
}

void MainMenu::draw (sf::RenderWindow &window)
{
    window.draw(m_spriteBackground);

    window.draw(m_spriteLogo);

    m_buttonSolo.draw(window);
    m_buttonMulti.draw(window);
}

MainMenu::~MainMenu()
{
    //dtor
}
