#include "Arrow.h"
#include "Unit.h"

Arrow::Arrow()
:m_position(-50, -50)
{
    m_texture.loadFromFile("resource/arrow.png");
    m_sprite.setTexture(m_texture);
}

void Arrow::update (sf::RenderWindow &window, Unit *unit)
{
    if (m_targetId != -1)
    {
       /*     std::cout << "arrow on " << m_targetId << std::endl;
        if (m_position.x < unit[m_targetId].getPosition().x)
            m_position.x++;
        else
            m_position.x--;

        if (m_position.y < unit[m_targetId].getPosition().y)
            m_position.y++;
        else
            m_position.y--;*/



        m_sprite.setPosition(m_position);
    }
}

void Arrow::draw (sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

void Arrow::setTargetID(int tid, sf::Vector2f position)
{
    m_targetId = tid;
    m_sprite.setPosition(position);
    m_position = position;
}

int Arrow::getTargetID()
{
    return m_targetId;
}

Arrow::~Arrow()
{
    //dtor
}
