#include "lineAlgorithm.hpp"

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

    for (xy x : drawLineAlgorithm({ input[0], input[1] }, { input[2], input[3] })) {
        S cout << x.x << ',' << x.y << '\n';
    }

    system("pause");
    return 0;
}