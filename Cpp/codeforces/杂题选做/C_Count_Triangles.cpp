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
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    i64 ans = 0;

    for (int x = a; x <= b; x++) {
        i64 l = b + x, r = c + x;

        if (l > d) {
            ans += (r - l + 1) * (d - c + 1);
            continue;
        } else if (r <= c) {
            continue;
        }

        if (l >= c) {
            if (r > d) {
                ans += ((l - c) + (d - c)) * (d - l + 1) / 2 +
                       (r - d) * (d - c + 1);
            }
            if (r <= d) {
                ans += ((l - c) + (r - c)) * (r - l + 1) / 2;
            }
        } else {
            if (r > d) {
                ans += ((c - c) + (d - c)) * (d - c + 1) / 2 +
                       (r - d) * (d - c + 1);
            }
            if (r <= d) {
                ans += ((c - c) + (r - c)) * (r - c + 1) / 2;
            }
        }
    }

    cout << ans << ln;
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
