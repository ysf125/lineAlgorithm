#define _USE_MATH_DEFINES
#include <cmath>
#include <array>
#include <vector>
#include <iostream>
#define S std::

template <typename T>

struct xy { T x, y; };

float getAngle(xy<int> point0, xy<int> point1);

int getWhichOctet(xy<int> point0, xy<int> point1);

xy<int> movePointInGrid(xy<int> point, int dir, int D = 1);

S vector<xy<int>> drawLineAlgorithm(xy<int> point0, xy<int> point1);