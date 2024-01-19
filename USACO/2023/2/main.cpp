#include <iostream>
#include <string>

using namespace std;

int findMinInfectedCows(string cows) {
    int minInfected = 0;
    int n = cows.length();

    for (int i = 0; i < n; ++i) {
        if (cows[i] == '1') {
            if (i == 0 || cows[i - 1] == '0') {
                minInfected++;
                if (i + 1 < n) cows[i + 1] = '1';
                if (i + 2 < n) cows[i + 2] = '1';
            }
        }
    }

    return minInfected;
}

int main() {
    int N;
    string cows;
    cin >> N;
    cin >> cows;
    cout << findMinInfectedCows(cows) << endl;
    return 0;
}
