#include <iostream>
#include <algorithm>
using namespace std;

const int R = 6, C = 6;
int num[R][C];

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> num[i][j];
        }
    }

    bool foundSaddlePoint = false;

    for (int i = 1; i <= 5; i++) {
        int maxInRow = num[i][1];
        int colIndexOfMax = 1;

        for (int j = 2; j <= 5; ++j) {
            if (num[i][j] > maxInRow) {
                maxInRow = num[i][j];
                colIndexOfMax = j;
            }
        }

        // 检查最大值是不是该列里的最小值
        bool isSaddlePoint = true;
        for (int k = 1; k <= 5; ++k) {
            if (num[k][colIndexOfMax] < maxInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << i << " " << colIndexOfMax << " " << maxInRow << endl;
            foundSaddlePoint = true;
            break; // 如果找到了鞍点，就不需要再继续查找
        }
    }

    if (!foundSaddlePoint) {
        cout << "not found" << endl;
    }

    return 0;
}
