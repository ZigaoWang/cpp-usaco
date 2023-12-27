// 1122：计算鞍点
// 解法 3
#include <iostream>
using namespace std;
const int R = 6, C = 6;
int num[R][C];

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            bool f1 = true;
            bool f2 = true;
            for (int k = 1; k <= 5; k++) {
                if (num[i][k] > num[i][j]) {
                    f1 = false;
                    break;
                }
            }
            for (int k = 1; k <= 5; k++) {
                if (num[k][j] < num[i][j]) {
                    f1 = false;
                    break;
                }
            }
            if (f1 == true && f2 == true) {
                cout << i << " " << j << " " << num[i][j] << endl;
                return 0;
            }
        }
    }

    cout << "not found";
    return 0;
}
