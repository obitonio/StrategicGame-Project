#include "Map.h"

Map::Map()
:m_dColor(111, 111, 49),
m_init(false), m_indexResolution(4), m_screenmode(false),
m_selectedTeam(1), m_labelSelectedTeam(sf::Vector2f(100, 25), "Selected team: "),
m_showLabel(true)
{
    std::stringstream ss;
    ss << m_selectedTeam;
    m_labelSelectedTeam.setString("Selected team: "+ss.str());


    m_background.create(SIZEX, SIZEY, m_dColor);
    m_texture.create(SIZEX, SIZEY);
    m_texture.update(m_background);
    m_sprite.setTexture(m_texture);

    m_view[m_indexResolution].setViewport(sf::FloatRect(0, 0, 1, 1));

    for (int i=0; i < MAX_OBJ; i++)
    {
        m_obj[i] = Drawable();
    }
    this->loadFromFile("map.txt");


    m_resolution[0] = sf::Vector2i(800, 600);
    m_resolution[1] = sf::Vector2i(1024, 768);
    m_resolution[2] = sf::Vector2i(1152, 648);
    m_resolution[3] = sf::Vector2i(1152, 864);
    m_resolution[4] = sf::Vector2i(1280, 720);
    m_resolution[5] = sf::Vector2i(1280, 1024);
    m_resolution[6] = sf::Vector2i(1360, 1024);
    m_resolution[7] = sf::Vector2i(1440, 900);
    m_resolution[8] = sf::Vector2i(1600, 900);
    m_resolution[9] = sf::Vector2i(1680, 1050);
    m_resolution[10] = sf::Vector2i(1920, 1080);

    m_view[0].reset(sf::FloatRect(0, 0, 800, 600));
    m_view[1].reset(sf::FloatRect(0, 0, 1024, 768));
    m_view[2].reset(sf::FloatRect(0, 0, 1152, 648));
    m_view[3].reset(sf::FloatRect(0, 0, 1152, 864));
    m_view[4].reset(sf::FloatRect(0, 0, 1280, 720));
    m_view[5].reset(sf::FloatRect(0, 0, 1280, 1024));
    m_view[6].reset(sf::FloatRect(0, 0, 1360, 1024));
    m_view[7].reset(sf::FloatRect(0, 0, 1440, 900));
    m_view[8].reset(sf::FloatRect(0, 0, 1600, 900));
    m_view[9].reset(sf::FloatRect(0, 0, 1680, 1050));
    m_view[10].reset(sf::FloatRect(0, 0, 1920, 1080));

}

void Map::update ()
{
    for (int i=0; i < MAX_OBJ; i++)
    {
        m_obj[i].update();
    }
}

void Map::draw (sf::RenderWindow &window)
{
    if (!m_init)
    {
        m_view[m_indexResolution] = window.getDefaultView();
        m_init = true;
    }
    window.setView(m_view[m_indexResolution]);
    window.draw(m_sprite); // Background

    for (int i=0; i < MAX_OBJ; i++)
    {
        m_obj[i].draw(window, 1); // enemyTeam = 1
    }
    for (int i=0; i<200; i++)
    {
        if (m_unit[i].getID() != -1)
        {
            m_unit[i].draw(window);
        }
    }

    if (m_showLabel)
    {
        //window.setView(m_labelView);
        //m_labelSelectedTeam.draw(window);
    }
}

void Map::addItem(int ID, sf::Vector2i pos)
{
    Drawable obj;
    Unit unit;
    int i, u;

    for (u=0; m_unit[u].getID() != -1; u++);

    switch (ID)
    {
    case 0:
        obj = Tree1(pos);
        break;
    case 1:
        obj = Tree2(pos);
        break;
    case 2:
        obj = Tree3(pos);
        break;
    case 3:
        obj = Road1(pos);
        break;
    case 4:
        obj = Bush1(pos);
        break;
    case 5:
        obj = Bush2(pos);
        break;
    case 6:
        obj = Bush3(pos);
        break;
    case 7:
        obj = Bush4(pos);
        break;
    case 12:
        obj = Barrack1(pos);
        break;
    case 13:
        obj = Barrack2(pos);
        break;
    case 14:
        obj = Barrack3(pos);
        break;
    case 15:
        obj = Barrack4(pos);
        break;
    case 16:
        obj = Ferme(pos);
        break;
    case 17:
        obj = Fruit(pos);
        break;
    case 18:
        obj = Market(pos);
        break;
    case 19:
        obj = Mill(pos);
        break;
    case 20:
        obj = House1(pos);
        break;
    case 21:
        obj = House2(pos);
        break;
    case 22:
        obj = House3(pos);
        break;
    case 23:
        obj = House4(pos);
        break;
    case 24:
        obj = House5(pos);
        break;
    case 25:
        obj = House6(pos);
        break;
    case 26:
        obj = House7(pos);
        break;
    case 27:
        obj = House8(pos);
        break;
    case 28:
        obj = Church(pos);
        break;
    case 32:
        unit = Soldier(pos, u, 1);
        break;
    case 33:
        unit = Soldier(pos, u, 2);
        break;
    }

    obj.setTeam(m_selectedTeam);

    bool nothingHere = true;

    for (i=0; i< MAX_OBJ; i++)
    {
        if (m_obj[i].isFloor() ||
            obj.getPosition().x + obj.getRect().width < m_obj[i].getPosition().x ||
            obj.getPosition().y + obj.getRect().height < m_obj[i].getPosition().y ||
            obj.getPosition().x > m_obj[i].getPosition().x + m_obj[i].getRect().width ||
            obj.getPosition().y > m_obj[i].getPosition().y + m_obj[i].getRect().height)
        {
        }
        else if(m_obj[i].isFloor() ||
            unit.getPosition().x + unit.getSize().x < m_obj[i].getPosition().x ||
            unit.getPosition().y + unit.getSize().y < m_obj[i].getPosition().y ||
            unit.getPosition().x > m_obj[i].getPosition().x + m_obj[i].getRect().width ||
            unit.getPosition().y > m_obj[i].getPosition().y + m_obj[i].getRect().height)
        {

        }
        else
        {
            nothingHere = false;
        }
    }
    if (nothingHere)
    {
        if (ID == 32 || ID == 33)
        {
            m_unit[u] = unit;
        }
        else
        {
            i = 0;
            while (m_obj[i].getType() != 0 && i < MAX_OBJ)
            {
                i++; //TODO Limite chaine
            }

            m_obj[i] = obj;
        }
        //std::cout << "Object created on i=" << i << std::endl;
        this->saveToFile("map.txt");
    }
}

void Map::moove (int x, int y)
{
    m_moove.x += x;
    m_moove.y += y;
    m_view[m_indexResolution].move(x, y);
}

bool Map::loadFromFile (const std::string &filename)
{
    std::ifstream stream(filename.c_str(), std::ios::in);  // on ouvre en lecture

        if(stream)
        {
            std::string line, values[3];
            while (std::getline(stream, line))
            {
                //std::cout << line << std::endl;


                int a = 0; // Nombre de parametre
                int i = 0; // Curseur dans le string
                int p[8]; // Enregistrement des parametres

                int nbV = 0; // Nombre de parametre
                while (a <= 3) // 3 parametre au total
                {

                    while (line[i] != ',')
                    {
                        values[a] += line[i]; // Enregistrement de la valeur en string
                        i++;
                    }
                    i++; // Saut de virgule dans le fichier
                    p[a] = std::atoi(values[a].c_str());
                    //std::cout << "str: " << values[a] << " int: " << std::atoi(values[a].c_str()) << std::endl; // String to int
                    values[a] = "";
                    a++; // Passage au Parametre suivant
                }

                i = 0;
                while (m_obj[i].getType() != 0 && i < MAX_OBJ)
                {
                    i++;
                }

                switch (p[0])
                {
                case 0:
                    m_obj[i] = Tree1(sf::Vector2i(p[1], p[2]));
                    break;
                case 1:
                    m_obj[i] = Tree2(sf::Vector2i(p[1], p[2]));
                    break;
                case 2:
                    m_obj[i] = Tree3(sf::Vector2i(p[1], p[2]));
                    break;
                case 3:
                    m_obj[i] = Road1(sf::Vector2i(p[1], p[2]));
                    break;
                case 4:
                    m_obj[i] = Bush1(sf::Vector2i(p[1], p[2]));
                    break;
                case 5:
                    m_obj[i] = Bush2(sf::Vector2i(p[1], p[2]));
                    break;
                case 6:
                    m_obj[i] = Bush3(sf::Vector2i(p[1], p[2]));
                    break;
                case 7:
                    m_obj[i] = Bush4(sf::Vector2i(p[1], p[2]));
                    break;
                case 12:
                    m_obj[i] = Barrack1(sf::Vector2i(p[1], p[2]));
                    break;
                case 13:
                    m_obj[i] = Barrack2(sf::Vector2i(p[1], p[2]));
                    break;
                case 14:
                    m_obj[i] = Barrack3(sf::Vector2i(p[1], p[2]));
                    break;
                case 15:
                    m_obj[i] = Barrack4(sf::Vector2i(p[1], p[2]));
                    break;
                case 16:
                    m_obj[i] = Ferme(sf::Vector2i(p[1], p[2]));
                    break;
                case 17:
                    m_obj[i] = Fruit(sf::Vector2i(p[1], p[2]));
                    break;
                case 18:
                    m_obj[i] = Market(sf::Vector2i(p[1], p[2]));
                    break;
                case 19:
                    m_obj[i] = Mill(sf::Vector2i(p[1], p[2]));
                    break;
                case 20:
                    m_obj[i] = House1(sf::Vector2i(p[1], p[2]));
                    break;
                case 21:
                    m_obj[i] = House2(sf::Vector2i(p[1], p[2]));
                    break;
                case 22:
                    m_obj[i] = House3(sf::Vector2i(p[1], p[2]));
                    break;
                case 23:
                    m_obj[i] = House4(sf::Vector2i(p[1], p[2]));
                    break;
                case 24:
                    m_obj[i] = House5(sf::Vector2i(p[1], p[2]));
                    break;
                case 25:
                    m_obj[i] = House6(sf::Vector2i(p[1], p[2]));
                    break;
                case 26:
                    m_obj[i] = House7(sf::Vector2i(p[1], p[2]));
                    break;
                case 27:
                    m_obj[i] = House8(sf::Vector2i(p[1], p[2]));
                    break;
                case 28:
                    m_obj[i] = Church(sf::Vector2i(p[1], p[2]));
                    break;
                case 32:
                    break;
                case 33:
                    break;

                }
                m_obj[i].setTeam(p[3]);
            }
                stream.close();
                return true;
        }
        else
        {
            return false;
        }


}

bool Map::saveToFile (const std::string &filename)
{

    std::ofstream stream(filename.c_str(), std::ios::out | std::ios::trunc);

    if(stream)
    {

            for (int i=0; i<MAX_OBJ; i++)
            {
                if (m_obj[i].getType() != 0)
                {
                    //std::cout <<"ID" << m_obj[i].getID() << m_obj[i].getType() << "," << m_obj[i].getPositionCenter().x << "," << m_obj[i].getPositionCenter().y << std::endl;
                    stream << m_obj[i].getType() << "," << m_obj[i].getPos().x << "," << m_obj[i].getPos().y << ","<< m_obj[i].getTeam()<<","<< std::endl;
                }
            }

            for (int i=0; i<200; i++)
            {
                if (m_unit[i].getID() != 0)
                {
                   // stream << m_unit[i].getID() << "," << m_unit[i].getPos().x << "," << m_unit[i].getPos().y << "," << m_unit[i].getAnimationIndex() << ","<< std::endl;
                    // TEAM
                }
            }

            stream.close();
            return true;
    }
    else
    {
        return false;
    }
}

void Map::changeResolution(int d, sf::RenderWindow &window)
{
    m_indexResolution = d;

    if (m_screenmode)
        window.create(sf::VideoMode(m_resolution[m_indexResolution].x, m_resolution[m_indexResolution].y), "AOE Editor", sf::Style::Fullscreen);
    else
        window.create(sf::VideoMode(m_resolution[m_indexResolution].x, m_resolution[m_indexResolution].y), "AOE Editor");

    window.setView(m_view[m_indexResolution]);
}

void Map::fullScreen(sf::RenderWindow &window)
{
    if (m_screenmode) // SI PLEIN ECRAN
    {
        window.create(sf::VideoMode(m_resolution[m_indexResolution].x, m_resolution[m_indexResolution].y), "AOE Editor");
        window.setView(m_view[m_indexResolution]);
        m_screenmode = false;
    }
    else
    {
        window.create(sf::VideoMode(m_resolution[m_indexResolution].x, m_resolution[m_indexResolution].y), "AOE Editor", sf::Style::Fullscreen);
        window.setView(m_view[m_indexResolution]);
        m_screenmode = true;
    }
}

Drawable* Map::getDrawable()
{
    return m_obj;
}

Unit* Map::getUnit()
{
    return m_unit;
}

int Map::getUnit(sf::Vector2i pos)
{
    for (int i=0; i<200; i++)
    {
        if (pos.x > m_unit[i].getPosition().x &&
            pos.x < m_unit[i].getPosition().x + m_unit[i].getSize().x &&
            pos.y > m_unit[i].getPosition().y &&
            pos.y < m_unit[i].getPosition().y + m_unit[i].getSize().y)
        {
            std::cout << "Unit " << i << " selected." << std::endl;
            return i;
        }
    }
    std::cout << "nothing" << std::endl;
    return -1;
}

sf::Vector2i Map::getSize()
{
    return sf::Vector2i(SIZEX, SIZEY);
}

sf::Vector2i Map::getMoove()
{
    return m_moove;

}

std::ofstream& operator <<(std::ofstream& stream, Drawable &drawable)
{
    stream << drawable.getType() << "," << drawable.getPositionCenter().x << "," << drawable.getPositionCenter().y << "," << std::endl;
}

std::ofstream& operator >>(std::ofstream& stream, Drawable &drawable)
{
    int t, px, py;
}

Drawable Map::getItem(sf::Vector2i pos)
{
   for (int i=0; i<MAX_OBJ; i++)
   {
       if (pos.x > m_obj[i].getPosition().x &&
           pos.x < m_obj[i].getPosition().x + m_obj[i].getSize().x &&
           pos.y > m_obj[i].getPosition().y &&
           pos.y < m_obj[i].getPosition().y + m_obj[i].getSize().y)
       {
            return m_obj[i];
       }
   }

   return Drawable();
}

bool Map::selectItem(sf::Vector2i pos, int *table, int index)
{
   for (int i=0; i<MAX_OBJ; i++)
   {
       if (pos.x > m_obj[i].getPosition().x &&
           pos.x < m_obj[i].getPosition().x + m_obj[i].getSize().x &&
           pos.y > m_obj[i].getPosition().y &&
           pos.y < m_obj[i].getPosition().y + m_obj[i].getSize().y)
       {
            if (!m_obj[i].isFocus())
            {
                m_obj[i].focus(1);
                table[index] = i;
                return true;
            }
            else
            {
                m_obj[i].focus(0);
                for (int a=0; a<MAX_OBJ; a++)
                {
                    if (table[a] == i)
                        table[a] = -1;
                }
            }
       }
   }
   return false;
}

 void Map::removeItem(int ID)
 {
     m_obj[ID] = Drawable();
     this->saveToFile("map.txt");
 }

sf::Vector2i Map::getResolution()
{
    return m_resolution[m_indexResolution];
}

void Map::flipUnit(int id)
{
   m_unit[id].getAnimation().flip();
}

bool Map::removeUnit(int ID)
{
   m_unit[ID] = Unit();
}

void Map::hideLabel()
{
    (m_showLabel)? m_showLabel=false: m_showLabel=true;
}

void Map::changeTeam()
{
    (m_selectedTeam ==1) ? m_selectedTeam=2 : m_selectedTeam=1;
    std::stringstream ss;
    ss << m_selectedTeam;
    m_labelSelectedTeam.setString("Selected team: "+ss.str());
    std::cout << m_selectedTeam << std::endl;
}

Map::~Map()
{
    //dtor
}
