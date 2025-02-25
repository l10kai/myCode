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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    vector<vector<int>> pre_0(31, vector<int>(n + 1, 0));
    vector<vector<int>> pre_1(31, vector<int>(n + 1, 0));

    for (int k = 0; k < 31; k++) {
        for (int j = 1; j <= n; j++) {
            pre_0[k][j] = pre_0[k][j - 1];
            pre_1[k][j] = pre_1[k][j - 1];
            if (((b[j - 1] >> k) & 1) == 0) {
                pre_0[k][j]++;
            } else {
                pre_1[k][j]++;
            }
        }
    }

    while (q--) {
        i64 l, r;
        cin >> l >> r;
        i64 ans = 0;
        i64 mod = 1e9 + 7;

        for (int k = 0; k < 31; k++) {
            i64 cot = 0;
            for (int i = l; i <= r; i++) {
                int tmp = 0;
                if (((a[i - 1] >> k) & 1) == 0) {
                    tmp = pre_1[k][r] - pre_1[k][i - 1];
                } else {
                    tmp = pre_0[k][r] - pre_0[k][i - 1];
                }
                cot += tmp;
            }
            ans = (ans + (cot % mod * (1 << k)) % mod) % mod;
        }
        cout << ans << ln;
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
