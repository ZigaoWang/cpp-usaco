#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int years[N];
    for (int i = 0; i < N; ++i) {
        cin >> years[i];
    }

    sort(years, years + N, greater<int>());

    int total_years = 0;
    for (int i = 0; i < N; i += K) {
        int jumps = min(K, N - i);
        total_years += 2 * (jumps - 1);

        if (i + K < N) {
            total_years += years[i] - years[i + K] + 12;
        }
    }

    cout << total_years << endl;

    return 0;
}
