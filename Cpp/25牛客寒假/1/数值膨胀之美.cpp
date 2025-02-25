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
    vector<i64> a(n);
    vector<pll> b(n);
    i64 minn = 1e18, maxx = -1e18;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].fi = a[i];
        b[i].se = i;
    }
    i64 ans = 1e18;
    sort(all(b));

    b.pb({2e9, -1});
    i64 old_min = b[0].fi * 2;
    i64 l, r;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            l = b[0].se;
            r = b[0].se;

            maxx = max(b[0].fi * 2, b[n - 1].fi);
            minn = min(b[1].fi, old_min);
            
            ans = min(ans, abs(maxx - minn));
            continue;
        }

            while (b[i].se > r) {
                r++;
                maxx = max(maxx, a[r] * 2);
            }

            while (b[i].se < l) {
                l--;
                maxx = max(maxx, a[l] * 2);
            }

        minn = min(b[i + 1].fi, old_min);
        ans = min(ans, abs(maxx - minn));
        // cerr << ans << " " << maxx << " " << minn << ln;
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
