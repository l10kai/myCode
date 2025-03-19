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

const i64 inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<i64>> dp(70, vector<i64>(70, inf));

    dp[0][0] = 0;
    for (int x = 0; x < 60; x++) {
        for (int i = 60; i >= 0; i--) {
            for (int j = 60; j >= 0; j--) {
                if (dp[i][j] == inf)
                    continue;
                if (i + x < 60)
                    dp[i + x][j] = min(dp[i + x][j], dp[i][j] + (1ll << x));
                if (j + x < 60)
                    dp[i][j + x] = min(dp[i][j + x], dp[i][j] + (1ll << x));
            }
        }
    }

    int t = 1;
    cin >> t;

    while (t--) {
        i64 x, y;
        cin >> x >> y;
        i64 ans = inf;

        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                if((x >> i) ==(y >> j)) {
                    ans  = min(ans, dp[i][j]);
                }
            }
        }

        cout << ans << ln;
    }
    // fin.close();
    // fout.close();
    return 0;
}
