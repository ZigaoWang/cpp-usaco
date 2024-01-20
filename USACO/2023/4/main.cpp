#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    char infect[n];
    for (int i = 0; i < n; i++) {
        cin >> infect[i];
    }
    int count[] = {0};
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n - i; j++) {
//            if (infect[i + j] == '1') {
//                count[i + j] = j;
//            }
//            else {
//                count[i] = 0;
//            }
//        }
//    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (infect[i + j] == '1') {
                count[i + j] = j;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    return 0;
}
