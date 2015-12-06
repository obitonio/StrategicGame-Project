#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>


#include <iostream>

#define SCREENX 1280
#define SCREENY 720

enum FunctionType { Affine = 1, SemiCircle = 2 };
struct EquationStruct {
    float a;
    float b;
    float c;
};

#endif // MAIN_H_INCLUDED
