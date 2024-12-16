#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    i64 idx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;

        if (x != -1) {
            g[x].push_back(i);
            deg[x]++;
        }

        else
            idx = i;
    }
    vector<bool> vis(n, false);
    vector<i64> ans;
    bool flag = false;

    function<void(i64)> dfs = [&](i64 x) {
        if (x != -1)
            ans.push_back(x);
        if (g[x].size() != g[idx].size() && g[x].size() != 0) {
            flag = true;
        }
        for (auto to : g[x]) {
            if (!vis[to]) {
                vis[to] = true;
                dfs(to);
                vis[to] = false;
            }
        }
    };

    vis[idx] = true;
    dfs(idx);

    cout << g[idx].size() << ' ' << (flag ? "no" : "yes") << ln;
    cout << ans[0] + 1;
    for(int i = 1; i < ans.size(); i ++) {
        cout << " " << ans[i] + 1;
    }
    
    return 0;
}
