#ifndef MULTIMENU_H
#define MULTIMENU_H

#include "../Main.hpp"

#include "../Tools/Button.h"

class MultiMenu
{
    public:
        MultiMenu();

        void update(sf::RenderWindow &window, int& state);

        void draw(sf::RenderWindow &window);

        virtual ~MultiMenu();
    protected:
    private:
        Button m_bServer;
        Button m_bClient;
};

#endif // MAINMENU_H
