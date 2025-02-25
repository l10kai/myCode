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

const i64 mod = 1e9 + 7;

i64 fpow(i64 a, i64 x) {
    i64 res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;

    if (n == 1) {
        cout << (str.front() == '?' ? 2 : 1) << ln;
        return;
    }

    i64 num = 0;
    for (int i = 1; i < n - 1; i++) {
        if (str[i] == '?')
            num++;
    }

    if (str.front() == '?' && str.back() == '?') {
        cout << fpow(2, num + 1) * n % mod << ln;
        return;
    }
    if (str.front() != '?' && str.back() != '?') {
        if (str.front() == str.back()) {
            cout << fpow(2, num) * (n - 2) % mod << ln;
        } else {
            cout << fpow(2, num + 1) % mod << ln;
        }

        return;
    }

    cout << fpow(2, num) * n % mod << ln;
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
