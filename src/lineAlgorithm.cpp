#include <iostream>
#define _USE_MATH_DEFINES
#include<cmath>
#include "lineAlgorithm.hpp"
#define S std::

float getAngle(xy point0, xy point1) {
    float angle = atan2(point1.y - point0.y, point1.x - point0.x);
    if (angle < 0) angle += M_PI * 2;
    return angle * (180 / M_PI);
}

int getWhichOctet(xy point0, xy point1) {
    return floor((360 - getAngle(point0, point1)) / 45);
}

int distance(xy point0, xy point1) {
    return sqrt(pow(point0.x - point1.x, 2) + pow(point0.y - point1.y, 2));
}

// I will change this later but for now just roll with it
xy movePointInGrid(xy point, int dir, int D) {
    int rad = 45 * (dir + 1) % 360 * (M_PI / 180);
    double x = point.x + (D * round(cos(rad))),
        y = point.y + (D * round(sin(rad)));
    return { x, y };
}