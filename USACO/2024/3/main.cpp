#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 2 * 10e5 + 50;
ll N;
ll bacteria[MAX_N];
ll total;
ll sum;
ll res;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> bacteria[i];
        total += sum;
        bacteria[i] = bacteria[i] + total;
        res += abs(bacteria[i]);
        sum = sum - bacteria[i];
        total = total - bacteria[i];
    }
    cout << res << endl;
    return 0;
}