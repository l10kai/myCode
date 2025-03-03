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

    string str;
    cin >> str;
    vector<i64> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](i64 x) {
        vector<int> need(n);

        for (int i = 0; i < n; i++) {
            if (str[i] == 'B' && a[i] > x)
                need[i] = 1;
            if (str[i] == 'R' && a[i] > x)
                need[i] = 2;
        }

        i64 cot = 0;
        for (int i = 0; i < n; i++) {
            if (need[i] == 1) {
                cot++;
                while (i < n && need[i] != 2)
                    i++;
            }
        }

        return cot <= k;
    };

    i64 l = 0, r = 1e18;
    while (l < r) {
        i64 mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << ln;
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
