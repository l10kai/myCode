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

    vector<pll> a(n);

    for (auto &[x, y] : a) {
        char ch1, ch2;
        i64 x1, x2;
        cin >> ch1 >> x1 >> ch2 >> x2;

        if (ch1 == '+') {
            x = x1;
        } else {
            x = -x1;
        }

        if (ch2 == '+') {
            y += x2;
        } else {
            y -= x2;
        }
    }

    i64 l = 1, r = 1, add = 0;

    for (int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        if (x > 0) {
            add += x;
        } else {
            add += l * (-x - 1);
        }
        if (y > 0) {
            add += y;
        } else {
            add += r * (-y - 1);
        }

        if (i != n - 1) {
            auto [x1, y1] = a[i + 1];

            if (x1 < 0 && y1 > 0) {
                l += add;
                add = 0;
            } else if (x1 > 0 && y1 < 0) {
                r += add;
                add = 0;
            } else if (x1 < 0 && y1 < 0) {
                if (x1 < y1) {
                    l += add;
                    add = 0;
                } else if(x1 > y1) {
                    r += add;
                    add = 0;
                }
                else add *= -x1;
            }
        }
    }

    cout << l + r + add << ln;
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
