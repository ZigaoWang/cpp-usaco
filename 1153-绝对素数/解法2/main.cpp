#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N], b[N], g[N], n;
int solve (int idx) {
    int st = idx, num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == st)st = b[i];
        else if (b[i] == st)st = a[i];
        if (st == g[i])num++;
    }
    return num;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }
    int res = 0;
    for (int)

    return 0;
}
