#include "Main.hpp"
#include "Games/GameClient.h"
#include "Games/GameServer.h"

#include "UI/MultiMenu.h"
#include "UI/MainMenu.h"
#include "UI/ConnectMenu.h"
#include "UI/LobbyServer.h"
#include "UI/LobbyConnect.h"

#include "Tools.hpp"

/*
Project started on 22/12/14
Target is to create a Age Of Empire like in 2D
*/

int main()
{
    sf::RenderWindow mainWindow(sf::VideoMode(SCREENX, SCREENY), "AOE game");
    mainWindow.setFramerateLimit(60);

    ConnectMenu connectMenu;

    MultiMenu multimenu;
    MainMenu mainmenu;

    LobbyServer lobbyServer;
    LobbyConnect lobbyConnect;

    int state = 0;

    while (mainWindow.isOpen())
    {
        sf::Event event;

        while (mainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                mainWindow.close();
            }
        }

        mainWindow.clear(sf::Color::White);
        switch (state)
        {
        case 0: // LAUNCHER
            connectMenu.update(mainWindow, event, state);
            connectMenu.draw(mainWindow);
            break;
        case 1: // MAINMENU
            mainmenu.update(mainWindow, state);
            mainmenu.draw(mainWindow);
            break;
        case 2: // MULTIMENU
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                state = 1;
            multimenu.update(mainWindow, state);
            multimenu.draw(mainWindow);
            break;
        case 3://CLIENT
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                state = 1;
            lobbyConnect.update(mainWindow, event);
            lobbyConnect.draw(mainWindow);
            break;
        case 4://SERVER
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                state = 1;
            lobbyServer.update(mainWindow, event);
            lobbyServer.draw(mainWindow);
            break;
        }
        mainWindow.display();
    }
    system("pause");
    return 0;
}
