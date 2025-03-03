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

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<i64> b1(n + 1), b2(n + 1);

    for (int i = 2; i <= n; i++) {
        if (a[i] <= a[i - 1]) {
            b1[i] = 1;
        }
        if (a[i] >= a[i - 1]) {
            b2[i] = 1;
        }
        b1[i] += b1[i - 1];
        b2[i] += b2[i - 1];
    }
    i64 ans = min(b1[n], b2[n] + 1);
    for (int i = 1; i <= n - 1; i++) {
        ans = min(b2[i] - b2[0] + b1[n] - b1[i + 1] + 1, ans);
    }
    cout << ans << ln;
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
