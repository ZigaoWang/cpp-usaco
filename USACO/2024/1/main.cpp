#include <iostream>
#include <algorithm>
using namespace std;
int type[1000];
int main() {
    int test = 0;
    cin >> test;
    int num = 0;
    for (int i = 0; i < test; i++) {
        cin >> num;
        int temp[1000] = {0};
        for (int j = 1; j <= num; j++) {
            cin >> type[j];
            if (j > 1 && type[j] == type[j - 1]) {
                temp[type[j]] = 1;
            }
            if (j > 2 && type[j] == type[j - 2]) {
                temp[type[j]] = 1;
            }
        }
        int possible = false;
        int place = 0;
        for (int k = 1; k <= num; k++) {
            if (temp[k] == 1) {
                place++;
                if (place != 1) {
                    cout << " ";
                }
                cout << k;
                possible = true;
            }
        }
        if (possible == false) {
            cout << "-1";
        }
        cout << endl;
//        sort(temp, temp + num);
//        for (int j = 0; j < num; j++) {
//            if (temp[j] != 0) {
//                cout << temp[j];
//                if (j < num - 1) {
//                    cout << " ";
//                }
//            }
//            if (temp[0] == 0 && temp[num - 1] == 0) {
//                cout << "-1";
//            }
//            while (temp[j] == temp[j + 1]) {
//                j++;
//            }
//        }
//        cout << endl;
    }


    return 0;
}
