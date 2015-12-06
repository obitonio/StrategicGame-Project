#ifndef LOBBYSERVER_H
#define LOBBYSERVER_H

#include "../Main.hpp"
#include "../Tools.hpp"
#include "../Games/GameServer.h"

class LobbyServer
{
    public:
        LobbyServer();

        void update(sf::RenderWindow &window, sf::Event &event);

        void draw(sf::RenderWindow &window);

        virtual ~LobbyServer();
    protected:
    private:
        GameServer game;

        Label m_labelTitle, m_labelStatus;
        Label m_labelIpLocal, m_labelIpPublic, m_labelPort;
        Label m_labelPlayer1, m_labelPlayer2;

        bool m_usernameIsOk, m_isBind, m_isConnected, m_isInGame;
        Textbox m_textbox, m_textboxPort;

        Button m_launchButton;

        sf::String m_username, m_clientUsername;

        sf::TcpSocket m_socket;
        sf::TcpListener m_listener;
};

#endif // LOBBYSERVER_H
