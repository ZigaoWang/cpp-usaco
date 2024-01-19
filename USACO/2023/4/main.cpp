#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    char infect[n];
    for (int i = 0; i < n; i++) {
        cin >> infect[i];
    }
    int count[n];
    for (int i = 0; i < n; i++) {
        if (infect[i] == '1') {
            count[i] = 0;
        } else {
            count[i] = 100000;
        }
    }
    cout << count << endl;
    return 0;
}