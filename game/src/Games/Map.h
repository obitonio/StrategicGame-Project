#ifndef MAP_H
#define MAP_H

#include "../Main.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include "../Drawable.h"

#include "../Drawable/Tree1.h"
#include "../Drawable/Tree2.h"
#include "../Drawable/Tree3.h"

#include "../Drawable/Bush1.h"
#include "../Drawable/Bush2.h"
#include "../Drawable/Bush3.h"
#include "../Drawable/Bush4.h"

#include "../Drawable/Barrack1.h"
#include "../Drawable/Barrack2.h"
#include "../Drawable/Barrack3.h"
#include "../Drawable/Barrack4.h"

#include "../Drawable/Ferme.h"
#include "../Drawable/Fruit.h"
#include "../Drawable/Market.h"
#include "../Drawable/Mill.h"

#include "../Drawable/House1.h"
#include "../Drawable/House2.h"
#include "../Drawable/House3.h"
#include "../Drawable/House4.h"
#include "../Drawable/House5.h"
#include "../Drawable/House6.h"
#include "../Drawable/House7.h"
#include "../Drawable/House8.h"

#include "../Drawable/Church.h"

#include "../Drawable/Road1.h"

#define MAX_OBJ 250

#define SIZEX 4000
#define SIZEY 4000

class Map
{
    public:
        Map();

        void update ();

        void draw (sf::RenderWindow &window, int enemyTeam);

        void addItem(int ID, sf::Vector2i pos);
        void removeItem(int ID);

        Drawable getItem(sf::Vector2i pos);
        bool selectItem(sf::Vector2i pos, int *table, int index);

        void moove (int x, int y);

        bool loadFromFile (const std::string &filename);
        bool saveToFile (const std::string &filename);

        void changeResolution(int d, sf::RenderWindow &window); // direction
        sf::Vector2i getResolution();
        void fullScreen(sf::RenderWindow &window);

        bool getScreenMode();

        Drawable* getDrawable();

        sf::Vector2i getSize();

        sf::Vector2i getMoove();

        std::ofstream& operator >>(Drawable &drawable);
        std::ofstream& operator <<(Drawable &drawable);

        virtual ~Map();
    protected:
    private:
        sf::Color m_dColor;
        sf::Image m_background;
        sf::Texture m_texture;
        sf::Sprite m_sprite;

        sf::Vector2i m_moove, m_resolution[16];
        sf::View m_view[16];

        int m_indexResolution;

        Drawable m_obj[MAX_OBJ+10];

        bool m_init, m_screenmode;
};

#endif // MAP_H
