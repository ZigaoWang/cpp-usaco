// 1109：开关灯
// 解法2
#include <iostream>

using namespace std;

const int N = 5010;
int num[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j % i == 0) {
                if (num[j] == 1) num[j] = 0;
                else num[j] = 1;
            }
        }
    }

    cout << 1;
    for (int i = 2; i <= n; i++) {
        if (num[i] == 0) {
            cout << "," << i;
        }
    }
    return 0;
}
