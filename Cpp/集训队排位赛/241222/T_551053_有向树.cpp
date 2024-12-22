#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

typedef pair<i64, i64> pll;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<i64>> g(n);

    vector<i64> in(n), out(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    vector<pll> dp(n, {-1, -1});

    function<pll(i64)> dfs = [&](i64 x) {
        i64 sum = 0, cnt = 0;
        if (g[x].empty()) {
            dp[x] = pll(0, 0);
            return dp[x];
        }
        if (dp[x] != pll(-1, -1)) {
            return dp[x];
        }

        for (auto to : g[x]) {
            auto [s, c] = dfs(to);
            cnt += c + 1;
            sum += s + c + 1;
        }

        dp[x] = pll(sum, cnt);
        return dp[x];
    };
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        ans += dp[i].first;
    }
    cout << ans << ln;

    return 0;
}