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
    i64 n, x, y;
    cin >> n >> x >> y;

    vector<i64> a(n + 1), s(n + 1);

    for (i64 i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    function<i64(i64)> f = [&](i64 x) {
        if (x <= n) {
            return a[x];
        }

        x /= 2;
        if (x <= n) {
            return s[x];
        }

        bool bl1 = (n + 1) & 1, bl2 = x & 1;

        if (bl1 && bl2) {
            return s[n] ^ f(n + 1);
        } else if (!bl1 && !bl2) {
            return s[n] ^ f(x);
        } else if (!bl1 && bl2) {
            return s[n];
        } else {
            return s[n] ^ f(n + 1) ^ f(x);
        }
    };

    cout << f(x) << ln;
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
