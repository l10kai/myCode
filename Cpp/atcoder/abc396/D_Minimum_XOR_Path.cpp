/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cstdint>
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

    vector<vector<pll>> g(n);

    for (i64 i = 0; i < m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    i64 ans = INT64_MAX;
    vector<bool> vis(n, false);
    function<void(i64, i64)> dfs = [&](i64 now, i64 cot) {
        if (now == n - 1)
            ans = min(ans, cot);
        // cout << now << " " << cot << ln;
        for (auto [to, w] : g[now]) {
            if (!vis[to]) {
                vis[to] = true;
                dfs(to, cot ^ w);
                vis[to] = false;
            }
        }
    };
    vis[0] = true;
    dfs(0, 0);
    cout << ans << ln;
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
