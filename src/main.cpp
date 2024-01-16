#include <iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include "lineAlgorithm.hpp"
#define S std::

int main(int argc, char* argv[]) {

    xy point0 = movePointInGrid({ 0,0 }, 4);

    S cout << point0.x << ',' << point0.y << "\n";

    return 0;
}