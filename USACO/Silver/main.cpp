#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
#define all(x) begin(x), end(x)
template <class T> using V = vector<T>;

using ll = int64_t;

const ll BIG = 1e18;

template <class T> void ckmin(T &a, T b) { a = min(a, b); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    ll T;
    array<V<ll>, 2> times;
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        char s;
        ll t;
        cin >> s >> t;
        times[s == 'B'].push_back(t);
    }
    for (int i = 0; i < 2; ++i) sort(all(times[i]));
    V<V<array<ll, 2>>> dp(size(times[0]) + 1,
                          V<array<ll, 2>>(size(times[1]) + 1, {BIG, BIG}));
    if (size(times[0])) dp.at(1).at(0).at(0) = 0;
    if (size(times[1])) dp.at(0).at(1).at(1) = 0;
    array<int, 2> sent_so_far{};
    ll ans = BIG;
    auto process_all = [&](int side) {
        const int i = ++sent_so_far[side];
        ll t = times[side].at(i - 1) + T;
        ll dp2 = BIG, add = 0;
        array<int, 2> cur{i, 0};

        // transition to dp or dp2
        auto get_dp = [&](int i, int j) {
            if (side) swap(i, j);
            return dp.at(i).at(j).at(side);
        };
        auto upd_dp = [&](int i, int j, ll v) {
            if (side) swap(i, j);
            ckmin(dp.at(i).at(j).at(side), v);
        };
        for (int j = (int)size(times[side ^ 1]); j >= 0; --j) {
            if (j < size(times[side ^ 1]) && times[side ^ 1].at(j) <= t) {
                add += t - times[side ^ 1].at(j);
                if (cur[1] == 0) cur[1] = j + 1;
            }
            ll v = get_dp(i, j);
            if (v != BIG) {
                assert(j == 0 ||
                       times.at(side).at(i - 1) > times.at(side ^ 1).at(j - 1));
                // stay on same side
                if (i < size(times[side])) upd_dp(i + 1, j, v);
                // or transition to dp2
                ckmin(dp2, v + add);
            }
        }

        // switch sides k times, transition from dp2 to dp
        if (side) swap(cur[0], cur[1]);
        for (int k = 1; k <= N; ++k, t += T) {
            const int s = (side + k) & 1;
            for (; cur.at(s) < size(times.at(s)) &&
                   times.at(s).at(cur.at(s)) <= t;
                   ++cur.at(s)) {  // send off all trains on current side
                // departing at time <= t
                dp2 += t - times.at(s).at(cur.at(s));
            }
            if (cur.at(s) == size(times.at(s))) {
                if (cur.at(s ^ 1) == size(times.at(s ^ 1))) ckmin(ans, dp2);
            } else {
                ckmin(
                        dp.at(cur.at(0) + (s == 0)).at(cur.at(1) + (s == 1)).at(s),
                        dp2);
            }
        }
    };
    // process states in increasing order of departure time
    while (sent_so_far[0] < size(times[0]) && sent_so_far[1] < size(times[1])) {
        if (times[0].at(sent_so_far[0]) < times[1].at(sent_so_far[1]))
            process_all(0);
        else process_all(1);
    }
    for (int side : {0, 1})
        while (sent_so_far[side] < size(times[side])) process_all(side);
    cout << ans << "\n";
}