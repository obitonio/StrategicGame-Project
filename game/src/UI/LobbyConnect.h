#ifndef LOBBYCONNECT_H
#define LOBBYCONNECT_H

#include "../Main.hpp"
#include "../Tools.hpp"
#include "../Games/GameClient.h"

class LobbyConnect
{
    public:
        LobbyConnect();

        void update(sf::RenderWindow &window, sf::Event &event);

        void draw(sf::RenderWindow &window);

        virtual ~LobbyConnect();
    protected:
    private:
        GameClient game;

        sf::TcpSocket m_socket;

        Label m_labelTitle, m_labelStatus;
        Label m_labelUsername, m_labelUsernameHost;

        Textbox m_textboxUsername;
        Textbox m_textboxIp;
        Textbox m_textboxPort;

        Button m_buttonConnect;

        sf::String m_username, m_hostUsername;

        bool m_isConnected, m_isInGame;
};

#endif // LOBBYCONNECT_H
