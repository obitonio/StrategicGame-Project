#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>

#define SCREENX 800
#define SCREENY 600

#define PORT 5000

enum FunctionType { Affine = 1, SemiCircle = 2 };
struct EquationStruct {
    float a;
    float b;
    float c;
};

#endif // MAIN_HPP_INCLUDED
