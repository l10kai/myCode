/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <iostream>
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
    vector<int> a(n + 1), p(n + 1), pp(n + 1);
    vector<bool> vis(n + 1, true);
    for (int i = 1; i <= n; i++) {
        a[i] = p[i] = pp[i] = i;
    }

    while (q--) {
        i64 ch, x, y;
        cin >> ch >> x;

        if (ch == 1) {
            cin >> y;
            a[x] = pp[y];
        }
        if (ch == 2) {
            cin >> y;
            swap(pp[x], pp[y]);
            swap(p[pp[x]], p[pp[y]]);
        }
        if (ch == 3) {
            cout << p[a[x]] << ln;
        }
    }
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
