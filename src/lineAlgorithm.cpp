#include "lineAlgorithm.hpp"

float getAngle(xy<int> point0, xy<int> point1) {
    if ((point0.x == point1.x) && (point0.y == point1.y)) return -1;
    float angle = atan2(point1.y - point0.y, point1.x - point0.x);
    if (angle < 0) angle += M_PI * 2;
    return angle * (180 / M_PI);
}

int getWhichOctet(xy<int> point0, xy<int> point1) {
    return floor(getAngle(point0, point1) / 45);
}

xy<int> movePointInGrid(xy<int> point, int dir, int D) {
    S array<xy<int>, 8> x = { 1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1 };
    dir %= 8;
    return { point.x + (x[dir].x * D), point.y + (x[dir].y * D) };
}

S vector<xy<int>> drawLineAlgorithm(xy<int> point0, xy<int> point1) {
    S vector<xy<int>> points = { point0 };
    float angle = getAngle(point0, point1);
    int octetNum = floor(angle / 45);
    while (true) {
        // calculating the points and angles
        xy newPoint0 = movePointInGrid(points[points.size() - 1], octetNum),
            newPoint1 = movePointInGrid(points[points.size() - 1], octetNum + 1);
        int point0Angle = getAngle(newPoint0, point1), point1Angle = getAngle(newPoint1, point1);
        // exiting the loop after calculating the angles
        if (point0Angle == -1 || point1Angle == -1) break;
        // adding the next point
        points.push_back(abs(angle - point0Angle) <= abs(angle - point1Angle) ? newPoint0 : newPoint1);
    }
    points.push_back(point1);
    return points;
}