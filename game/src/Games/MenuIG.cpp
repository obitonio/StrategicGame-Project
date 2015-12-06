#include "MenuIG.h"

MenuIG::MenuIG(Drawable *drawable, int team)
:m_rect(sf::Vector2f(0, 0)), m_posBuild(125, 25),
m_id(-1),
m_drawable(drawable),
m_totalUnits(0),
m_team(team)
{
    m_rect.setFillColor(sf::Color::White);
    m_rect.setOutlineColor(sf::Color::Black);
    m_rect.setOutlineThickness(2);

    m_spriteBuilding.setPosition(25, 25);

    m_view.setViewport(sf::FloatRect(0.1f, 0.8f, 1, 1));
}

void MenuIG::draw(sf::RenderWindow &window)
{
    window.setView(m_view);
    window.draw(m_rect);
    if (m_id != -1)
    {
        window.draw(m_spriteBuilding);
        for (int i=0; i<m_totalUnits; i++)
        {
            m_spriteUnit.setTexture(m_textureUnits[i]);
            m_spriteUnit.setPosition(m_posBuild.x+i*30, m_posBuild.y);
            window.draw(m_spriteUnit);
        }
    }
}

void MenuIG::update(sf::RenderWindow &window, Order &order)
{
    window.setView(m_view);
   // std::cout << "x: " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).x <<
   // " y: " << window.mapPixelToCoords(sf::Mouse::getPosition(window)).y<< std::endl;
    //==============================Unlock id==============================
    if (m_id != -1 && m_unlockClock.getElapsedTime().asSeconds() > 2 &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < 0 ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < 0 ||
        sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > m_rect.getSize().x ||
         sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > m_rect.getSize().y )
    {
        m_id = -1;
    }


    //==============================In menu to add unit==============================
    if (m_id != -1)
    {
        sf::IntRect rect(m_posBuild.x, m_posBuild.y, 30, 25);

        for (int i=0;i< m_totalUnits; i++)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                window.mapPixelToCoords(sf::Mouse::getPosition(window)).x > rect.left &&
                window.mapPixelToCoords(sf::Mouse::getPosition(window)).x < rect.left + rect.width &&
                window.mapPixelToCoords(sf::Mouse::getPosition(window)).y > rect.top &&
                window.mapPixelToCoords(sf::Mouse::getPosition(window)).y < rect.top + rect.height &&
                m_unitClock.getElapsedTime().asSeconds() > 1)
            {
                if (m_team == 1) // Serveur
                {
                     order.apply(1, m_unitType[i], sf::Vector2f(100, 100));
                }
                else if (m_team == 2) // Client
                {
                    order.send(1, m_unitType[i], sf::Vector2f(100, 300));
                }
                m_unitClock.restart();
            }
            rect.left += rect.width;
        }
    }

}

void MenuIG::setDrawable(Drawable* drawable)
{
    m_drawable = drawable;
}

void MenuIG::init(sf::Vector2i resolution)
{
    m_rect.setSize(sf::Vector2f(resolution.x/3, resolution.y*2/10));
    m_rect.setPosition(5, 5);
}

 void MenuIG::setID(int id)
 {
     m_totalUnits=0;
     m_id = id;
    // std::cout << "menuIG: Load id: " << m_id << std::endl;
    // std::cout << " and texture " << std::string(m_drawable[m_id].getImgLink()) << std::endl;
    if (m_id != -1)
    {

         m_unitsList = m_drawable[m_id].getUnitsList();

         m_textureBuilding.loadFromFile(m_drawable[m_id].getImgLink());
         m_spriteBuilding.setTexture(m_textureBuilding);

        for (int i=0; i<8; i++)
        {
            //std::cout << "Unitslist: " << i << " "<< m_unitsList[i] << std::endl;
            switch(m_unitsList[i])
            {
            case 1: // Soldier
                m_textureUnits[i].loadFromFile("resource/menuIG/soldier.png"); // Soldier
                m_totalUnits++;
                m_unitType[i] = 1;
                break;
            case 2:
                break;
            case 3: // Bowman
                break;
            }
        }

    }
    m_unlockClock.restart();
 }

MenuIG::~MenuIG()
{

}
