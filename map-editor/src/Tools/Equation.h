#ifndef EQUATION_H
#define EQUATION_H

#include "../Main.h"
#include <cmath>

class Equation
{
    public:

        Equation();
        Equation(int mode, sf::Vector2f A, sf::Vector2f B, sf::Vector2f C = sf::Vector2f(0, 0));

        bool isInit();

        float f(float x);

        EquationStruct getComp();
        virtual ~Equation();
    protected:
    private:
        EquationStruct m_e;
        sf::Vector2f m_A, m_B, m_C;
        bool m_is;
        int m_mode;
};

#endif // EQUATION_H
