// 1119：矩阵交换行
// 解法 1
#include <iostream>
#include <algorithm>
const int R = 6, C = 6;
int num[R][C];

using namespace std;

int main() {
    int n, m;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> num[i][j];
        }
    }

    cin >> n >> m;
    for (int i = 1; i <= 5;i++) {
        swap(num[n][i], num[m][i]);
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << num[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
