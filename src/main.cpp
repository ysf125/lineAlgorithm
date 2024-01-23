#include "lineAlgorithm.hpp"

int main(int argc, char* argv[]) {
    S array<int, 4> inputPoints;
    S string algorithm;
    S vector<xy<int>> returnVal;

    if (argc == 6) {
        algorithm = argv[1];
        for (int i = 2; i < argc; i++) {
            inputPoints[i - 2] = S stoi(argv[i]); 
        }
    } else {
        S array<S string,4> x = {"x0", "y0", "x1", "y1"};
        S cout << "enter the line algorithm : ";
        S cin >> algorithm;
        for (int i = 0; i < 4; i++) {
            S cout << "enter " << x[i] << " : ";
            S cin >> inputPoints[i];
        }
    }

    if (algorithm == "midline") {

    } else if (algorithm == "angline") {
        returnVal = angline({inputPoints[0], inputPoints[1]}, {inputPoints[2], inputPoints[3]});
    } else if (algorithm == "brehensam") {
    
    } else { return 0; }

    for (int i = 0; i < returnVal.size(); i++) {
        S cout << returnVal[i].x << "," << returnVal[i].y << "\n";
    }

    system("pause");
    return 0;
}