#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    char infect[n];
    for (int i = 0; i < n; i++) {
        cin >> infect[i];
    }

    int count[100000];
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
//    for (int i = 0; i < n; i++) {
//        cout << count[i] << endl;
//    }
    int cow = 0;
    for (int i = 0; i < countIndex; i++) {
        cow += count[i];
    }
    for (int i = 0; i < countIndex; i++) {
        count[i] = count[i] / 2;
    }
    int minCount = *min_element(count, count + countIndex);
    cout << (cow - minCount * 2) << endl;
    return 0;
}