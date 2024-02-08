#include <iostream>
using namespace std;
const int MAX_N  = 10e5 + 50;
int main() {
    int T = 0;
    int N = 0;
    int cookieTime = 0;
    int muffinTime = 0;
    int a[MAX_N], b[MAX_N], c[MAX_N];
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> cookieTime >> muffinTime;
        for (int k = 0; k < N; k++) {
            cin >> a[k] >> b[k] >> c[k];
        }
    }

    return 0;
}
