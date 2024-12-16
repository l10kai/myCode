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

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }

    



    return 0;
}
