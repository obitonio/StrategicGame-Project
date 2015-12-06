#include "LobbyServer.h"
//TODO Refacroring of LobbyServer
LobbyServer::LobbyServer()
: m_labelTitle(sf::Vector2f(100, 10), "Game open"),
m_labelStatus(sf::Vector2f(300, 150), "Online", 10),
m_labelIpLocal(sf::Vector2f(300, 50), "Local: "+sf::IpAddress::getLocalAddress().toString(), 15),
m_labelIpPublic(sf::Vector2f(300, 80), "Public: "+sf::IpAddress::getPublicAddress().toString(), 15),
m_labelPort(sf::Vector2f(300, 110), "Port: ", 15),
m_labelPlayer1(sf::Vector2f(50, 100), "Player1", 25),
m_labelPlayer2(sf::Vector2f(50, 140), "Player2", 25),
m_textbox(sf::Vector2f(100, 100), "username"),
m_textboxPort(sf::Vector2f(100, 150), "5000"),
m_launchButton("resource/bok.png", "resource/bok.png", sf::Vector2f(100, 200)),
m_clientUsername("Player2"),
m_usernameIsOk(false), m_isBind(false), m_isConnected(false), m_isInGame(false),
game(m_socket)
{
    m_socket.setBlocking(false);
    m_listener.setBlocking(false);
}

void LobbyServer::update(sf::RenderWindow &window, sf::Event &event)
{
    if (m_isInGame)
    {
        game.update(window, m_socket);
    }
    else if (m_usernameIsOk)
    {
        if (!m_isBind)
        {
            if (m_listener.listen(m_textboxPort.getShort()) == sf::Socket::Done)
            {
                 std::cout << "Serveur online" << std::endl;
            }
            m_isBind = true;
        }
        else if(!m_isConnected)
        {
            if (m_listener.accept(m_socket) != sf::Socket::Done)
            {
               // std::cout << "[Server] Error accept"<< std::endl;
            }
            else // CONNECTION OF CLIENT
            {
                m_labelStatus.setString("Client connected from " + m_socket.getRemoteAddress().toString());
                m_isConnected = true;
            }
        }
        else
        {
            sf::Packet p1, p2;
            if (m_clientUsername == "Player2" && m_socket.receive(p1) == sf::Socket::Done)
            {
                p1 >> m_clientUsername;
                m_labelPlayer2.setString(m_clientUsername);
                p2 << m_username;
                if (m_socket.send(p2) == sf::Socket::Done)
                    std::cout << "Username sended" << std::endl;
            }

            if (m_clientUsername != "Player2" && m_launchButton.mousePressed(window))
            {
                sf::Packet packet;
                packet << 1; // HERE TO SEND GAME PARAM

                if (m_socket.send(packet) == sf::Socket::Done)
                    m_isInGame = true;
            }
        }
    }
    else
    {
        m_textbox.update(window, event);
        m_textboxPort.update(window, event);
        if (m_launchButton.mousePressed(window))
        {
            m_username = m_textbox.getText();
            m_labelPlayer1.setString(m_username);
            m_labelPort.setString("Port: "+m_textboxPort.getText());
            m_launchButton.setPosition(sf::Vector2f(50, 400));
            m_usernameIsOk = true;
        }
    }
}

void LobbyServer::draw(sf::RenderWindow &window)
{
    if (m_isInGame)
    {
        game.draw(window);
    }

    else if(m_usernameIsOk)
    {
        m_labelTitle.draw(window);
        m_labelStatus.draw(window);
        m_labelIpLocal.draw(window);
        m_labelIpPublic.draw(window);
        m_labelPort.draw(window);
        m_labelPlayer1.draw(window);
        m_labelPlayer2.draw(window);
        m_launchButton.draw(window);
    }
    else
    {
        m_labelTitle.draw(window);
        m_textbox.draw(window);
        m_textboxPort.draw(window);
        m_launchButton.draw(window);
    }
}

LobbyServer::~LobbyServer()
{
    //dtor
}
