#ifndef ORDER_H
#define ORDER_H

#include "Main.h"

#include "Map.h"

class Order
{
    public:
        Order(Map &map);

        void update ();
        /*
            In need to be launched in a thread or the application will not work
        */

        virtual ~Order();
    protected:
    private:
        Map &m_map;
};

#endif // ORDER_H
