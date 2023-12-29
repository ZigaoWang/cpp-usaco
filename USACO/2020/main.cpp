#include <iostream>

using namespace std;
const int MAX_N = 100;

int petals[MAX_N];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> petals[i];
    }

    int count = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += petals[k];
            }

            int length = j - i + 1;
            if (sum % length == 0) {
                int avg = sum / length;
                for (int k = i; k <= j; ++k) {
                    if (petals[k] == avg) {
                        count++;
                        break;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}