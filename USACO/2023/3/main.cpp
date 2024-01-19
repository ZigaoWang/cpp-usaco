#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Plant {
    ll h, a, t;
};

bool cmp(const Plant &x, const Plant &y) {
    if (x.a != y.a) return x.a > y.a;
    return x.h < y.h;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        Plant plants[200005];
        for (int i = 0; i < N; i++) cin >> plants[i].h;
        for (int i = 0; i < N; i++) cin >> plants[i].a;
        for (int i = 0; i < N; i++) cin >> plants[i].t;
        sort(plants, plants + N, cmp);
        ll pq[200005], top = 0;
        ll days = 0;
        for (int i = 0; i < N; i++) {
            while (top < plants[i].t) {
                if (i == N || plants[i].a != plants[i+1].a) days++;
                else i++;
            }
            if (top < plants[i].t) {
                cout << -1 << "\n";
                break;
            }
            pq[top++] = plants[i].h + days * plants[i].a;
            sort(pq, pq + top);
            while (top > plants[i].t) top--;
        }
        if (top == plants[N-1].t) cout << days << "\n";
    }
    return 0;
}