#include "LobbyConnect.h"
//TODO Refacroring of LobbyConnect
LobbyConnect::LobbyConnect()
:m_labelTitle(sf::Vector2f(100, 10), "Connect to game"),
m_labelStatus(sf::Vector2f(300, 100), "Offline", 10),
m_textboxUsername(sf::Vector2f(100, 100), "username"),
m_textboxIp(sf::Vector2f(100, 150), "localhost"),
m_textboxPort(sf::Vector2f(100, 200), "5000", 55, 30, 4),
m_buttonConnect("resource/bconnect.png", "resource/bconnect.png", sf::Vector2f(100, 400)),
m_isConnected(false), m_isInGame(false),
m_labelUsername(sf::Vector2f(50, 100), "Player1", 25),
m_labelUsernameHost(sf::Vector2f(50, 150), "Player2", 25),
m_hostUsername("Player2"),
game(m_socket)
{
    m_socket.setBlocking(false);
}

void LobbyConnect::update(sf::RenderWindow &window, sf::Event &event)
{
    if(!m_isConnected)
    {
        m_textboxUsername.update(window, event);
        m_textboxIp.update(window, event);
        m_textboxPort.update(window, event);

        if (m_buttonConnect.mousePressed(window))
        {
            m_username = m_textboxUsername.getText();
            sf::Socket::Status status = m_socket.connect(sf::IpAddress(m_textboxIp.getText()), m_textboxPort.getShort());;
            if (status == sf::Socket::Done)
            {
                m_labelStatus.setString("Connected as " + m_username);
                sf::Packet p1;

                p1<< m_username;
                m_socket.send(p1);

                m_labelUsername.setString(m_username);
                m_isConnected = true;
            }
            else
            {
                m_labelStatus.setString("Cant' connect to " + m_textboxIp.getText());
            }
        }
    }
    else if (m_isInGame)
    {
        game.update(window, m_socket);
    }
    else
    {
        if (m_hostUsername == "Player2")
        {
                sf::Packet packet;
                if (m_socket.receive(packet) == sf::Socket::Done)
                {
                    packet >> m_hostUsername;
                    m_labelUsernameHost.setString(m_hostUsername);
                }
        }
        else
        {
                sf::Packet packet;
                if (m_socket.receive(packet) == sf::Socket::Done)
                {
                    int a;
                    packet >> a;
                    if (a == 1)
                        m_isInGame = true;
                }
        }
    }
}

void LobbyConnect::draw(sf::RenderWindow &window)
{


    if (!m_isConnected)
    {
        m_labelTitle.draw(window);
        m_labelStatus.draw(window);
        m_textboxUsername.draw(window);
        m_textboxIp.draw(window);
        m_textboxPort.draw(window);

        m_buttonConnect.draw(window);
    }
    else if (m_isInGame)
    {
        game.draw(window);
    }
    else
    {
        m_labelTitle.draw(window);
        m_labelStatus.draw(window);
        m_labelUsername.draw(window);
        m_labelUsernameHost.draw(window);
    }
}

LobbyConnect::~LobbyConnect()
{
    //dtor
}
