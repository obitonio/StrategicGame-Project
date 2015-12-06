#include "Animation.h"

Animation::Animation(sf::String texturelink, sf::Vector2i position)
:m_iTexture(0), m_iFight(-1), m_position(position),
m_sprite(), m_maxFrame(0), m_maxFrameFight(0)
, m_direction(1), m_isFlip(false)
{
    m_sprite.setPosition(m_position.x, m_position.y);
}

void Animation::next()
{
    if (m_iFight != -1 && m_clock.getElapsedTime().asSeconds() >= 0.5)
    {
        if (m_direction == -1)
            m_sprite.setTextureRect(m_rectfightPosLeft[m_iFight]);
        else if (m_direction == 1)
            m_sprite.setTextureRect(m_rectfightPosRight[m_iFight]);
        /*
        std::cout << m_rectfightPos[m_iFight].left << " y: "<<m_rectfightPos[m_iFight].top <<
        " w: " << m_rectfightPos[m_iFight].width << " h: " << m_rectfightPos[m_iFight].height << std::endl;
        */
        if (m_iFight >= m_maxFrameFight)
            m_iFight = -1;
        else
            m_iFight++;

        m_clock.restart();
    }
    else if (m_iFight == -1)
    {
        if (m_direction == -1)
            m_sprite.setTextureRect(m_rectPosLeft[m_iTexture]);
        else if (m_direction == 1)
            m_sprite.setTextureRect(m_rectPosRight[m_iTexture]);

        if (m_iTexture >= m_maxFrame)
            m_iTexture = 1;
        else
            m_iTexture++;
    }


}

void Animation::nextLeft()
{
    m_direction = -1;
    this->flip();
    this->next();
}

void Animation::nextRight()
{
    m_direction = 1;
    this->flip();
    this->next();
}

void Animation::standing()
{
    if (m_iFight == -1)
    {
        m_iTexture = 0;

        if (m_direction == 1) // RIGHT
        {
            m_sprite.setTextureRect(m_rectPosRight[m_iTexture]);
        }
        else if (m_direction == -1) // LEFT
        {
            m_sprite.setTextureRect(m_rectPosLeft[m_iTexture]);
        }
    }
}

void Animation::update()
{
    if (m_iFight != -1)
        this->next();
}

void Animation::fight()
{
    std::cout << "FIGHT" << std::endl;
    m_iFight = 0;
  //  m_sprite.setTextureRect(m_rectfightPos[m_iFight]);
}

void Animation::setPosition(sf::Vector2i position)
{
    m_position = position;
    m_sprite.setPosition(m_position.x, m_position.y);
}

void Animation::setTexture(sf::String link)
{
    m_texture.loadFromFile(link);
    m_sprite.setTexture(m_texture);
}

void Animation::draw(sf::RenderWindow &window)
{
    m_sprite.setTexture(m_texture);

    if (m_sprite.getTexture())
        window.draw(m_sprite);
    else
        std::cout << "Animation: Can't draw texture !" << std::endl;
}

void Animation::setIndex(int i)
{
    m_iTexture = i;
    if (m_iTexture != 0)
        this->next();
    else
        this->standing();
}

sf::Vector2i Animation::getSize()
{
    if (m_direction == 1)
        return sf::Vector2i(m_rectPosRight[m_iTexture].width, m_rectPosRight[m_iTexture].height);
    else
        return sf::Vector2i(m_rectPosLeft[m_iTexture].width, m_rectPosLeft[m_iTexture].height);
}

int Animation::getIndex()
{
    return m_iTexture;
}

void Animation::setMaxFrame(int frame, int fightFrame)
{
    m_maxFrame = frame - 1;
    m_maxFrameFight = fightFrame - 1;
}

void Animation::setRectPosition(sf::IntRect rect, int i, int ifight, bool right)
{
    if (i != -1)
    {
        if (!right)
            m_rectPosLeft[i] = rect;
        else
            m_rectPosRight[i] = rect;
    }
    else if (ifight != -1)
    {
        if (!right)
            m_rectfightPosLeft[ifight] = rect;
        else
            m_rectfightPosRight[ifight] = rect;
    }

    m_sprite.setTextureRect(m_rectPosLeft[m_iTexture]);

   /* for (int i=0; i<m_maxFrame; i++)
    {
        std::cout << "x: " << m_rectPos[i].left << " y: " << m_rectPos[i].top << " w: " << m_rectPos[i].width << " h: " << m_rectPos[i].height << std::endl;
    }*/
}

void Animation::flip()
{
    if (m_direction == 1 && !m_isFlip)
    {
        m_img = m_texture.copyToImage();
        m_img.flipHorizontally();
        m_texture.loadFromImage(m_img);
        m_sprite.setTexture(m_texture);
    }
    else if (m_direction == -1 && m_isFlip)
    {
        m_img = m_texture.copyToImage();
        m_img.flipHorizontally();
        m_texture.loadFromImage(m_img);
        m_sprite.setTexture(m_texture);
    }
}

 void Animation::flipPosition()
 {
    sf::IntRect t[10];

    /*for (int i=0; i<m_maxFrame; i++)
        t[i] = m_rectPosLeft[i];

    for (int i=0, a=m_maxFrame; i<m_maxFrame; i++, a--)
    {
        m_rectPosRight[i].left = t[a].left;
    }*/
    //////////////////////////////////////////////////////
    for (int i=0; i<m_maxFrameFight; i++)
        t[i] = m_rectfightPosLeft[i];

    for (int i=0, a=m_maxFrameFight; i<m_maxFrameFight; i++, a--)
    {
        m_rectfightPosRight[i].left = 0;
        for (int b=m_maxFrameFight; b>i; b--)
        {
            std::cout <<"b: " << b << " i: " << i << " a: " << m_rectfightPosRight[i].left << " + " << m_rectfightPosLeft[b].left << std::endl;
            m_rectfightPosRight[i].left += m_rectfightPosLeft[b].left;
        }
        std::cout << "----------------------------" << std::endl;
    }
    std::cout << "========================" << std::endl;

    for (int i=0; i<=m_maxFrameFight; i++)
    {
        std::cout << "x: " << m_rectfightPosRight[i].left << " y: " << m_rectfightPosRight[i].top << " w: " << m_rectfightPosRight[i].width << " h: " << m_rectfightPosRight[i].height << std::endl;
    }
    std::cout << std::endl;
 }

void Animation::setDirection(int direction)
{

    if (direction != m_direction)
    {
        m_direction = direction;
        this->flip();
    }
}

Animation::~Animation()
{
    delete m_rectPosLeft;
    delete m_rectfightPosRight;
}
