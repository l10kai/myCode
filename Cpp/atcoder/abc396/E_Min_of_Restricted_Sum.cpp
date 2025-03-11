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
    i64 n, m;
    cin >> n >> m;

    vector<i64> x(n + 1), y(n + 1), z(n + 1);

    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> z[i];
        if (x[i] == y[i]) {
            cout << -1 << ln;
            return;
        }
    }

    vector<vector<pll>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        g[x[i]].pb({y[i], z[i]});
        g[y[i]].pb({x[i], z[i]});
    }


    function<i64(i64, i64)> dfs = [&](i64 now, i64 cot) {
        for (auto [to, w] : g[now]) {
            
        }
    };

    for (int bit = 32; bit >= 0; bit--) {
        for (int i = 1; i <= n; i++) {
            i64 res1 = 0, res2 = 0;
            res1 = dfs(1, 1);
            res2 = dfs(1, 0);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
