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
    int n, k;
    cin >> n >> k;

    vector<pll> a(n);
    for (auto &[l, _] : a) {
        cin >> l;
    }
    for (auto &[_, r] : a) {
        cin >> r;
    }

    if (k == 0) {
        i64 minn = 0, tmp = 0;
        sort(all(a), [](const pll &x, const pll &y) {
            return x.fi <= y.fi;
        });

        for (int i = 0; i < n; i++) {
            if (tmp < a[i].fi)
                minn = max(minn, a[i].fi * (n - i));

            tmp = max(tmp, a[i].se);
        }

        cout << minn << ln;
        return;
    }

    sort(all(a), [](const pll &x, const pll &y) {
        return x.se >= y.se;
    });
    i64 ans = 0;
    for (int i = 0; i <= k - 1; i++) {
        ans = max(ans, (i + 1) * a[i].se);
    }
    i64 ans_2 = 0;

    i64 l = a[n - k].fi;
    for (int i = n - 1; i >= n - k; i--) {
        i64 tmp = 0;
        l = a[i].fi;
        for (int i = 0; i < n; i++) {
        if (l <= a[i].fi) {
            tmp += l;
        } else if (l <= a[i].se) {
            tmp += l;
        }
    }

    ans_2 = max(ans_2, tmp);
    }

    
    cout << max(ans, ans_2) << ln;
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
