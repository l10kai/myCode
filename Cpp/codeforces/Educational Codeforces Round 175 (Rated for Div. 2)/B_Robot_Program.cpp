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
    i64 n, x, k;
    cin >> n >> x >> k;

    string str;
    cin >> str;

    i64 pos = x, cot = 0, idx = 0;
    while (pos != 0 && idx != n && cot != k) {
        cot++;
        if (str[idx] == 'L') {
            pos--;
        } else {
            pos++;
        }
        idx++;
    }

    if (pos != 0) {
        cout << 0 << ln;
        return;
    }

    i64 loop_cot = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'L') {
            pos--;
        } else {
            pos++;
        }

        if (pos == 0) {
            loop_cot = i + 1;
            break;
        }
    }

    if (loop_cot == -1 || k - cot < loop_cot) {
        cout << 1 << ln;
    } else {
        cout << (k - cot) / loop_cot + 1 << ln;
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
