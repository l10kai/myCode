#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n + 10, vector<int>(m + 10));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    auto find1 = [&]() {
        vector<vector<int> > res(n + 10, vector<int>(m + 10));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                res[i][j] = max(res[i - 1][j], res[i][j - 1]) + g[i][j];
            }
        }

        return res;
    };

    auto find2 = [&]() {
        vector<vector<int> > res(n + 10, vector<int>(m + 10));

        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                res[i][j] = max(res[i + 1][j], res[i][j + 1]) + g[i][j];
            }
        }

        return res;
    };

    auto find3 = [&]() {
        vector<vector<int> > res(n + 10, vector<int>(m + 10));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                res[i][j] = max(res[i + 1][j], res[i][j - 1]) + g[i][j];
            }
        }

        return res;
    };

    auto find4 = [&]() {
        vector<vector<int> > res(n + 10, vector<int>(m + 10));

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                res[i][j] = max(res[i - 1][j], res[i][j + 1]) + g[i][j];
            }
        }

        return res;
    };

    auto dp1 = find1(), dp2 = find2(), dp3 = find3(), dp4 = find4();
    int ans = -1;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            ans = max(max(ans, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] +
                                   dp4[i - 1][j]),
                      max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] +
                                   dp4[i][j + 1]));
        }
    }
    cout << ans << endl;
    return 0;
}