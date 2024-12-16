#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    int n;
    cin >> n;

    vector<vector<i64>> g(n);
    vector<i64> deg(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        deg[x]++;
        deg[i]++;

        g[x].push_back(i);
        g[i].push_back(x);
    }
    i64 ans = -1;
    vector<bool> vis(n);
    function<void(i64, i64)> dfs = [&](i64 x, i64 deepth) {
        ans = max(ans, deepth);
        i64 add_deepth = log2(deg[x]);
        for (auto y : g[x]) {
            if (!vis[y]) {
                vis[y] = true;
                dfs(y, deepth + add_deepth + 1);
                vis[y] = false;
            }
        }
        return;
    };

    vis[0] = true;
    dfs(0, 0);
    cout << ans << ln;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
