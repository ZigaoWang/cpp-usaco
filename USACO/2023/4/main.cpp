#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    char infect[n];
    for (int i = 0; i < n; i++) {
        cin >> infect[i];
    }

    int* count = new int[n];
    int temp = 0;
    int countIndex = 0;
    for (int i = 0; i < n; i++) {
        if (infect[i] == '1') {
            temp++;
        } else {
            if (temp > 0) {
                count[countIndex++] = temp;
                temp = 0;
            }
        }
    }
    if (temp > 0) {
        count[countIndex++] = temp;
    }

    for (int i = 0; i < countIndex; i++) {
        cout << count[i] << " ";
    }
    delete[] count;
    return 0;
}