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
    int n;
    cin >> n;

    vector<string> g(n + 1);
    vector<tuple<int, int, int, int>> ans;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int jj = j;
            if (jj > 1)
                while (g[i][jj] == '1' && g[i][jj - 1] == '0' && jj > 1 &&
                       jj <= n) {
                    swap(g[i][jj], g[i][jj - 1]);

                    ans.pb({i, jj, i, jj - 1});
                    jj--;
                    if (jj == 1)
                        break;
                }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            int ii = i;
            if (ii > 1)
                while (g[ii][j] == '1' && g[ii - 1][j] == '0' && ii > 1 &&
                       ii <= n) {
                    swap(g[ii][j], g[ii - 1][j]);
                    ans.pb({ii, j, ii - 1, j});

                    ii--;
                    if (ii == 1)
                        break;
                }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cerr << g[i][j];
    //     }
    //     cerr << ln;
    // }
    // cerr << "-----------------" << ln;

    for (int i = n / 2 + 1; i <= n; i++) {
        for (int j = n / 2; j >= 1; j--) {
            if (g[i][j] == '0')
                continue;

            i64 x = -1, y = -1;
            for (int ii = 1; ii <= n / 2; ii++) {
                for (int jj = 1; jj <= n / 2; jj++) {
                    if (g[ii][jj] == '0') {
                        x = ii;
                        y = jj;

                        break;
                    }
                }
                if (x != -1)
                    break;
            }
            for (int jj = j; jj < y; jj++) {
                swap(g[i][jj], g[i][jj + 1]);
                ans.pb({i, jj, i, jj + 1});
            }

            for (int ii = i; ii > x; ii--) {
                swap(g[ii][y], g[ii - 1][y]);
                ans.pb({ii, y, ii - 1, y});
            }
        }
    }

    for (int i = n / 2; i >= 1; i--) {
        for (int j = n / 2 + 1; j <= n; j++) {
            if (g[i][j] == '0')
                continue;
            i64 x = -1, y = -1;
            for (int ii = 1; ii <= n / 2; ii++) {
                for (int jj = 1; jj <= n / 2; jj++) {
                    if (g[ii][jj] == '0') {
                        x = ii;
                        y = jj;

                        break;
                    }
                }
                if (x != -1)
                    break;
            }
            // cerr << "i = " << i << " j = " << j << " x = " << x << " y = " << y
            //      << ln;
            for (int ii = i; ii < x; ii++) {
                swap(g[ii][j], g[ii + 1][j]);
                ans.pb({ii, j, ii + 1, j});
            }
            for (int jj = j; jj > y; jj--) {
                swap(g[x][jj], g[x][jj - 1]);
                ans.pb({x, jj, x, jj - 1});
            }
        }
    }

    cout << ans.size() << ln;
    for (auto [a, b, c, d] : ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << ln;
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
