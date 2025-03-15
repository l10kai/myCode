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

i64 mod = 1e9 + 7;

i64 fpow(i64 a, i64 x) {
    i64 res = 1;
    while (x) {
        if (x & 1)
            res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res % mod;
}

const i64 M = 1e5;
i64 fac[M + 10], fnv[M + 10];

void init() {
    fac[0] = 1;
    for (int i = 1; i <= M; i++)
        fac[i] = fac[i - 1] * i % mod;
    fnv[M] = fpow(fac[M], mod - 2);
    for (int i = M; i >= 1; i--)
        fnv[i - 1] = fnv[i] * i % mod;
    // assert(fnv[1] == 1);
}

i64 C(i64 n, i64 m) {
    if (m < 0 || m > n)
        return 0;
    return fac[n] * fnv[m] % mod * fnv[n - m] % mod;
}  // c(n,m)
i64 A(i64 n, i64 m) {
    if (m < 0 || m > n)
        return 0;
    return fac[n] * fnv[n - m] % mod;
}  // a(n,m);

void solve() {

    
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
