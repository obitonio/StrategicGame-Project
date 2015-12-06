#include "Minimap.h"

Minimap::Minimap(Map &map)
: m_drawable(map.getDrawable()),
m_dColor(111, 111, 49), m_blackColor(0, 0, 0),
m_rectScroll(sf::Vector2f(0, 0)), m_image()
{
    int d = 5;
// Taille map Divisé par l'ecran puis par 5, donc minimap 5 fois plus petite que ecran
     m_coef.x = map.getSize().x/(SCREENX/d);
     m_coef.y = map.getSize().y/(SCREENY/d);
// Dimenssions divisées par le coefficient -> PROPORTIONALITE
     m_coefScroll.x = SCREENX/m_coef.x;
     m_coefScroll.y = SCREENY/m_coef.y;

    m_size.x = SCREENX/d;
    m_size.y =SCREENY/d;

    m_image.create(SCREENX/d, SCREENY/d, m_dColor);
    m_texture.create(SCREENX/d, SCREENY/d);
    m_texture.update(m_image);

    m_sprite.setTexture(m_texture);

    m_view.setViewport(sf::FloatRect(0.75f, 0.05f, 1, 1)); // MINIMAP POSITION

    m_rect.setSize(sf::Vector2f(SCREENX/d, SCREENY/d));
    m_rect.setOutlineColor(sf::Color::Black);
    m_rect.setOutlineThickness(2);

    m_rectScroll.setSize(m_coefScroll);
    m_rectScroll.setOutlineColor(sf::Color::Black);
    m_rectScroll.setOutlineThickness(2);
    m_rectScroll.setFillColor(sf::Color::Transparent);

    m_rect.setPosition(1, 1);
    m_sprite.setPosition(1, 1);
}

void Minimap::update(Map &map)
{
    m_rectScroll.setPosition(sf::Vector2f(map.getMoove().x/m_coef.x, map.getMoove().y/m_coef.y));

   // std::cout << map.getMoove().x << " " << map.getMoove().y << std::endl;
    m_image.create(m_size.x, m_size.y, m_dColor);

    for (int i=0; i<MAX_OBJ; i++)
    {
        if (m_drawable[i].getType() != 0
            && m_drawable[i].getPosition().x/m_coef.x > 0
            && m_drawable[i].getPosition().y/m_coef.y > 0)
        {

            m_image.setPixel(m_drawable[i].getPosition().x/m_coef.x, m_drawable[i].getPosition().y/m_coef.y, m_blackColor);
            m_image.setPixel(m_drawable[i].getPosition().x/m_coef.x+1, m_drawable[i].getPosition().y/m_coef.y, m_blackColor);
            m_image.setPixel(m_drawable[i].getPosition().x/m_coef.x, m_drawable[i].getPosition().y/m_coef.y+1, m_blackColor);
            m_image.setPixel(m_drawable[i].getPosition().x/m_coef.x+1, m_drawable[i].getPosition().y/m_coef.y+1, m_blackColor);
        }
    }
    m_texture.update(m_image);

}

void Minimap::draw(sf::RenderWindow &window)
{
    window.setView(m_view);
    window.draw(m_rect);
    window.draw(m_sprite);
    window.draw(m_rectScroll);

}

Minimap::~Minimap()
{
    //dtor
}
