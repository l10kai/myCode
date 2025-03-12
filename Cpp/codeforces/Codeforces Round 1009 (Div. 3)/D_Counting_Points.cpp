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
#define pii pair<i64, i64>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;

using u32 = unsigned;
using i64 = int64_t;

const char &ln = '\n';

void solve() {
    i64 n, m;
    cin >> n >> m;

    vector<pll> a(n);

    for (i64 i = 0; i < n; i++) {
        cin >> a[i].fi;
    }
    for (i64 i = 0; i < n; i++) {
        cin >> a[i].se;
    }
    map<i64, i64> mp;

    for (auto [x, r] : a) {
        for (i64 j = x - r; j <= x + r; j++) {
            if (!mp[j]) {
                mp[j] = floor(sqrt(r * r - (x - j) * (x - j))) * 2 + 1;
            } else {
                mp[j] =
                    max(mp[j], (i64)sqrt(r * r - (x - j) * (x - j)) * 2 + 1);
            }
        }
    }
    i64 ans = 0;
    for (auto [key, value] : mp) {
        ans += value;
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
