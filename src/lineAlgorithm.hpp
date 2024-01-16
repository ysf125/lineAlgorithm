#ifndef lineAlgorithm_hpp 
#define lineAlgorithm_hpp
#define S std::

struct xy { double x, y; };

float getAngle(xy point0, xy point1);

int getWhichOctet(xy point0, xy point1);

int distance(xy point0, xy point1);

xy movePointInGrid(xy point, int dir, int D = 1);

#endif