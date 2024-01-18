#define _USE_MATH_DEFINES
#include <cmath>
#include <array>
#include <vector>
#include <iostream>
#define S std::

struct xy { int x, y; };

float getAngle(xy point0, xy point1) {
    if ((point0.x == point1.x) && (point0.y == point1.y)) return -1;
    float angle = atan2(point1.y - point0.y, point1.x - point0.x);
    if (angle < 0) angle += M_PI * 2;
    return angle * (180 / M_PI);
}

xy movePointInGrid(xy point, int dir, int D = 1) {
    S array<xy, 8> x = { 1, 0, 1, 1, 0, 1, -1, 1, -1, 0, -1, -1, 0, -1, 1, -1 };
    dir %= 8;
    return { point.x + (x[dir].x * D), point.y + (x[dir].y * D) };
}

S vector<xy> darwLine(xy point0, xy point1) {
    S vector<xy> points = { point0 };
    float angle = getAngle(point0, point1);
    int octetNum = floor(angle / 45);
    while (true) {
        // calculating the points and angles
        xy nextPoint0 = movePointInGrid(points[points.size() - 1], octetNum),
            nextPoint1 = movePointInGrid(points[points.size() - 1], octetNum + 1);
        int point0Angle = getAngle(nextPoint0, point1), point1Angle = getAngle(nextPoint1, point1);
        // exiting the loop after calculating the angles
        if (point0Angle == -1 || point1Angle == -1) break;
        // adding the next point
        points.push_back(abs(angle - point0Angle) <= abs(angle - point1Angle) ? nextPoint0 : nextPoint1);
    }
    points.push_back(point1);
    return points;
}

int main(int argc, char* argv[]) {
    S array<int, 4> input;

    for (int i = 1; i < argc; i++) {
        input[i - 1] = S atoi(argv[i]);
    }

    if (argc <= 4) {
            S array<char[3],4> x = { "x0", "y0", "x1", "y1" };
            for (int i = 0; i < 4; i++) {
                S cout << "enter "  << x[i] << ": ";
                S cin >> input[i];
            }
    }

    for (xy x : darwLine({ input[0], input[1] }, { input[2], input[3] })) {
        S cout << x.x << ',' << x.y << '\n';
    }

    system("pause");
    return 0;
}