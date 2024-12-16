#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

typedef pair<int, int> pii;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<char> > g(n + 10, vector<char>(m + 10));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    auto f = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
        i64 res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (abs(i - x1) + abs(j - y1) <= d ||
                    abs(i - x2) + abs(j - y2) <= d) {
                    if (g[i][j] == '.') {
                        res++;
                    }
                }
            }

        return res;
    };

    i64 ans = 0;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int j1 = 1; j1 <= m; j1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                for (int j2 = 1; j2 <= m; j2++) {
                    if (make_pair(i1, j1) == make_pair(i2, j2)) {
                        continue;
                    }
                    if (g[i1][j1] == '#' || g[i2][j2] == '#') {
                        continue;
                    }
                    ans = max(ans, f(i1, j1, i2, j2));
                }
            }
        }
    }

    cout << ans << ln;
    return 0;
}
