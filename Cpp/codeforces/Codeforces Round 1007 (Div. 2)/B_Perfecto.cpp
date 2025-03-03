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
map<i64, i64> mp;

void solve() {
    i64 n;
    cin >> n;

    if (mp[(1 + n) * n / 2]) {
        cout << -1 << ln;
        return;
    }

    vector<i64> ans(n + 1);
    for (i64 i = 1; i <= n; i++) {
        ans[i] = i;
    }

    for (i64 i = 1; i < n; i++) {
        if (mp[(1 + i) * i / 2]) {
            swap(ans[i], ans[i + 1]);
            cerr << i << ln;
        }
    }
    for (i64 i = 1; i <= n; i++) {
        cout << ans[i] << " ";
       
    }
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (i64 i = 0; i <= 1000000; i++) {
        mp[i * i] = 1;
    }

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
