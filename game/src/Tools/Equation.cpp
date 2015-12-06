#include "Equation.h"

Equation::Equation(int mode, sf::Vector2f A, sf::Vector2f B, sf::Vector2f C)
: m_A(A), m_B(B), m_C(C), m_mode(mode)
{
    if (mode == 1) // Affine
    {
        if (A.x == B.x)
        {
            B.x += 1;
        }

        m_e.a = (B.y - A.y)/(B.x-A.x); //x1 != x2 !!!
        m_e.b = (B.x*A.y-A.x*B.y)/(B.x-A.x);
        //m_e.b = (B.y*A.x-A.y*B.x)/(A.x - B.x);

        //std::cout << "Equation: a=" << m_e.a << " b=" << m_e.b << std::endl;
        m_is = true;
    }
    else if (mode == 2) // Semi-circle
    {

    }
    //ctor
}

Equation::Equation()
: m_is(false)
{

}

 float Equation::f(float x)
 {
     if (m_mode == 1)
     {
         return m_e.a*x+m_e.b;
     }
     else if (m_mode == 2)
     {
         float r, omegaX, omegaY;

         if (m_B.x - m_A.x > 0)
         {
            r = (m_B.x - m_A.x)/2;
            omegaX = m_B.x + r;
            omegaY = m_B.y + r;
         }
         else
         {
            r = (m_A.x - m_B.x)/2;
            omegaX = m_A.x + r;
            omegaY =m_A.y + r;
         }

         return std::sqrt(r*r-(x-omegaX)*(x-omegaX))+omegaY;
     }
 }

bool Equation::isInit()
{
    return m_is;
}

EquationStruct Equation::getComp()
{
    return m_e;
}

Equation::~Equation()
{
    //dtor
}
