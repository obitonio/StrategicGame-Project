#include "MultiMenu.h"

MultiMenu::MultiMenu()
:m_bClient("resource/bc.png", sf::Vector2f(100, 50)),
m_bServer("resource/bs.png", sf::Vector2f(100, 150))
{
    //ctor
}

void MultiMenu::update(sf::RenderWindow &window, int& state)
{
    if (m_bClient.mousePressed(window))
        state = 3;
    else if (m_bServer.mousePressed(window))
        state = 4;
}

void MultiMenu::draw(sf::RenderWindow &window)
{
    m_bClient.draw(window);
    m_bServer.draw(window);
}

MultiMenu::~MultiMenu()
{
    //dtor
}
