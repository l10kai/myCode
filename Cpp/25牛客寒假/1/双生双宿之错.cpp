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

    for (auto &x : a)
        cin >> x;

    sort(all(a));

    i64 l_mid, r_mid;

    if ((n / 2) % 2 == 0) {
        l_mid = (a[n / 4 - 1] + a[n / 4]) / 2;
        r_mid = (a[n - n / 4] + a[n - n / 4 - 1]) / 2;

    } else {
        l_mid = a[n / 4];
        r_mid = a[n - n / 4 - 1];
    }
    // cerr << l_mid << ' ' << r_mid << ln;
    if (l_mid != r_mid) {
        i64 sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += abs(a[i] - l_mid) + abs(a[i + n / 2] - r_mid);
        }
        cout << sum << ln;
    } else {
        i64 sum1 = 0, sum2 = 0;

        for (int i = 0; i < n / 2; i++) {
            sum1 += abs(a[i] - (l_mid - 1)) + abs(a[i + n / 2] - r_mid);
            sum2 += abs(a[i] - l_mid) + abs(a[i + n / 2] - (r_mid + 1));
        }

        cout << min(sum1, sum2) << ln;
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
