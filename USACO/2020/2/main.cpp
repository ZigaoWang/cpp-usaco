#include <iostream>
using namespace std;

string s1, s2;
int N, ans;

int main() {
    cin >> N >> s1 >> s2;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (s2[i] != s1[i]) {
            if (!flag) {
                flag = true;
                ans++;
            }
            else {
                flag = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}