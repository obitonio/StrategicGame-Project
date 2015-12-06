#include "Order.h"

Order::Order(Map &map)
:m_map(map)
{
    std::cout << "Welcome on the AOE map editor" << std::endl << std::endl;
    std::cout << "Type \"help\" for more information" << std::endl;
}

void Order::update ()
{
    while (1) // I'm in a thread !
    {
        std::string str;

        std::getline(std::cin, str);

        if (str == "help")
        {
            std::cout << "No help !" << std::endl;
        }
        else
        {
            std::cout << "This function does not exist !" << std::endl;
        }
    }

}

Order::~Order()
{
    //dtor
}
