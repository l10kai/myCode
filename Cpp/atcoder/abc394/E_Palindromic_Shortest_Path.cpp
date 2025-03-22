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
    int n;
    cin >> n;

    vector<string> g(n);

    vector<vector<int>> dis(n, vector<int>(n, 0x3f3f3f));

    for (auto &x : g)
        cin >> x;

    queue<pii> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (g[i][j] != '-') {
                dis[i][j] = 1;
                q.push({i, j});
            }
            dis[i][i] = 0;
            q.push({i, i});
        }

    auto check = [&](int i, int x, int y, int j) {
        return g[i][x] == g[y][j] && g[i][x] != '-';
    };


    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (check(i, x, y, j) && dis[i][j] > dis[x][y] + 2) {
                    dis[i][j] = dis[x][y] + 2;
                    q.push({i, j});
                }
            }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (dis[i][j] == 0x3f3f3f ? -1 : dis[i][j])
                 << " \n"[j == n - 1];
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
