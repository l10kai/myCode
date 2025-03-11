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
    i64 sum = 0, tmp = 0, x = 0, y = 0, m;
    cout << 0 << ln;
    cout.flush();
    cin >> sum;
    cout << 357913941 << ln;
    cout.flush();
    cin >> tmp;

    cout << "!" << ln;
    cout.flush();
    cin >> m;
    tmp -= sum;

    for (int i = 29; i >= 1; i -= 2) {
        bool l = (tmp >> i) & 1, r = (tmp >> (i - 1)) & 1;
        if (!l && r) {
            x |= 1 << (i - 1);
        } else if (!l && !r) {
            x |= 1 << (i - 1);
            y |= 1 << (i - 1);
        }
    }

    sum -= x + y;

    for (int i = 31; i >= 1; i--) {
        if ((sum >> i) & 1) {
            if ((i & 1))
                x |= 1 << i;
            else {
                x |= 1 << (i - 1);
                y |= 1 << (i - 1);
            }
        }
    }

    cout << (m | x) + (m | y) << ln;
    cout.flush();
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
