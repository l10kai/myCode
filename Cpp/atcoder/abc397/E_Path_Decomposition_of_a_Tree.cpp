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

void solve() {}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<i64>> g(n * k);
    vector<i64> siz(n * k);
    for (int i = 0; i < n * k - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    function<void(int, int)> dfs = [&](int now, int from) {
        siz[now] = 1;
        i64 son_num = 0;
        for (auto to : g[now]) {
            if (to == from)
                continue;
            dfs(to, now);
            if (siz[to]) {
                son_num++;
                siz[now] += siz[to];
            }
        }

        if (siz[now] < k) {
            if (now == 0 || son_num > 1) {
                cout << "No" << ln;
                exit(0);
            }
        } else if (siz[now] > k) {
            cout << "No" << ln;
            exit(0);
        } else {
            if (son_num > 2) {
                cout << "No" << ln;
                exit(0);
            }
            siz[now] = 0;
        }
    };

    dfs(0, -1);
    cout << "Yes" << ln;
    // fin.close();
    // fout.close();
    return 0;
}
