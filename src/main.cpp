#include "lineAlgorithm.hpp"

int main(int argc, char* argv[]) {
    S array<int, 4> inputPoints;
    xy<int> point0, point1;

    if (argc == 5) {
        for (int i = 1; i < argc; i++) {
            inputPoints[i - 1] = S stoi(argv[i]);
        }
    }
    else {
        S array<S string, 4> x = { "x0", "y0", "x1", "y1" };
        for (int i = 0; i < 4; i++) {
            S cout << "enter " << x[i] << " : ";
            S cin >> inputPoints[i];
        }
    }

    point0 = { inputPoints[0], inputPoints[1] };
    point1 = { inputPoints[2], inputPoints[3] };

    for (xy<int> point : angline(point0, point1)) {
        S cout << point.x << "," << point.y << "\n";
    }

    system("pause");
    return 0;
}