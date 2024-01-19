#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    char infect[n];
    for (int i = 0; i < n; i++) {
        cin >> infect[i];
    }
    for (int i = 0; i < n; i++) {
        if (infect[i] == '1') {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
