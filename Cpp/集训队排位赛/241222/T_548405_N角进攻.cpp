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
    deque<i64> left, right;

    for (int i = 1; i < (n + 1) / 2; i++) {
        left.pb(i);
    }
    for (int i = (n + 1) / 2 + 1; i <= n; i++) {
        right.pb(i);
    }
    i64 mid = (n + 1) / 2;

    k %= n * 2;
    while (k--) {
        if (x == 0) {
            left.push_front(mid);
            mid = left.back();
            left.ppb();
        } else {
            right.push_back(mid);
            mid = right.front();
            right.pop_front();
        }
        x =x ^ 1;
    }

    for (auto i : left) {
        cout << i << " ";
    }
    cout << mid << " ";
    for (auto i : right) {
        cout << i << " ";
    }
    cout << ln;
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
