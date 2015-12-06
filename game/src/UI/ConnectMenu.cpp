#include "ConnectMenu.h"

ConnectMenu::ConnectMenu()
:m_textboxMail(sf::Vector2f(325, 250), "mail@gmail.com", 200, 30, 15),
m_textboxMdp(sf::Vector2f(325, 300), "15", 200, 30, 15),
m_labelMail(sf::Vector2f(250, 245), "Mail:"),
m_labelMdp(sf::Vector2f(250, 295), "Pass:"),
m_labelInfo(sf::Vector2f(200, 500), ""),
m_buttonConnect("resource/menu/connection.png", "resource/menu/connection2.png", sf::Vector2f(300, 350))
{
    m_textboxMdp.hideChar(1);

    m_backgroundTexture.loadFromFile("resource/menu/connect.jpg");
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setPosition(0, 0);

    m_textureLogo.loadFromFile("resource/menu/logo_aoe.png");
    m_spriteLogo.setTexture(m_textureLogo);
    m_spriteLogo.setPosition(200, 0);
}

void ConnectMenu::update(sf::RenderWindow &window, sf::Event &event, int& state)
{
    m_textboxMail.update(window, event);
    m_textboxMdp.update(window, event);
    if (m_buttonConnect.mouseReleased(window))
    {
        if (this->connect(m_textboxMail.getText(), m_textboxMdp.getText()))
        {
            state = 1;
        }
        else
        {
            m_labelInfo.setString("Mail ou Mot de Passe incorrect !");
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) // SECURITY
    {//====================
        state = 1;
    } //===================
}

void ConnectMenu::draw(sf::RenderWindow &window)
{
    window.draw(m_backgroundSprite);

    window.draw(m_spriteLogo);

    m_textboxMail.draw(window);
    m_textboxMdp.draw(window);

    m_labelMail.draw(window);
    m_labelMdp.draw(window);
    m_labelInfo.draw(window);

    m_buttonConnect.draw(window);
}

bool ConnectMenu::connect(sf::String mail, sf::String mdp)
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");
    char *requete;
    char a[16];
    std::string str = "SELECT id FROM inscription WHERE mail = \"" + mail + "\"AND mdp =\"" + mdp + "\"";
    requete = (char*)str.c_str();

    if(mysql_real_connect(&mysql,"127.0.0.1","root","","aoe",0,NULL,0))
    {

        std::cout << "===Connected to db===" << std::endl;
        std::cout << "Query is " << requete << std::endl;
        mysql_query(&mysql, requete); // WHERE mail = \"AM@gmail.com\"AND mdp =\"mdp\"

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;
        unsigned int num_champs = 0;

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);
        num_champs = mysql_num_fields(result);
        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
             unsigned long *lengths;

            //On stocke ces tailles dans le pointeur
            lengths = mysql_fetch_lengths(result);
            //On fait une boucle pour avoir la valeur de chaque champs
            for(i = 0; i < num_champs; i++)
            {
               sprintf(a, "%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
            }
        }

        //Libération du jeu de résultat

       // std::cout << a << "::" << std::atoi(a) << std::endl;
       // mysql_free_result(result);

        //mysql_close(&mysql);


        if ( std::atoi(a) > 0)
        {
            std::cout << "success !" << std::endl;
            return 1;
        }
        std::cout << "failure !" << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Une erreur s'est produite lors de la connexion à la BDD!" << std::endl;
        return 0;
    }
}

ConnectMenu::~ConnectMenu()
{
    //dtor
}
