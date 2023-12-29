#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y;
    fin >> x >> y;

    int step = 1; // Initial step size (x + 1)
    int totalDistance = 0;
    int position = x; // Farmer John's current position

    while (true) {
        // Calculate the next position
        int nextPosition = x + step;

        // Update the total distance traveled
        totalDistance += abs(nextPosition - position);

        // Check if Farmer John has reached or passed Bessie's position
        if ((step > 0 && nextPosition >= y && y >= position) ||
            (step < 0 && nextPosition <= y && y <= position)) {
            // Adjust the total distance to Bessie's exact position and break
            totalDistance -= abs(nextPosition - y);
            break;
        }

        // Update Farmer John's position and prepare for the next step
        position = nextPosition;
        step *= -2; // Reverse direction and double the step size
    }

    fout << totalDistance << endl;

    return 0;
}
