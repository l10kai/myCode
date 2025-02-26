/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    int k;
    cin >> k;
    i64 sum = 0, idx = 1, x = 1, y = 1;

    vector<pii> ans;
    while (k > 0) {
        while (sum <= k) {
            sum += idx;
            idx++;
        }
        idx--;
        sum -= idx;

        // cerr << sum << ' ' << idx << ln;

        for (int i = x; i < x + idx; i++) {
            ans.pb({i, y});
        }

        y++;
        x += idx;
        k -= sum;
        sum = 0;
        idx = 1;
    }

    cout << ans.size() << ln;
    for (auto &i : ans) {
        cout << i.fi << ' ' << i.se << ln;
    }
}

void solve2() {
    int k;
    cin >> k;

    vector<pii> ans;
    while (k > 0) {
        i64 idx = 1, x = 1, y = 1;
        while (idx * (idx - 1) / 2 <= k) {
            idx++;
        }
        idx--;

        k -= idx * (idx - 1) / 2;
        for (int i = x; i < x + idx; i++) {
            ans.pb({i, y});
        }

        y++;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
