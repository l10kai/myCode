#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 mod = 1e9 + 7;

i64 fpow(i64 a, i64 b) {
    i64 res = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) {
    return fpow(x, mod - 2);
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    i64 total = 0;
    i64 factorial[x + 1];
    factorial[0] = 1;
    for (int i = 1; i <= x; ++i)
        factorial[i] = factorial[i - 1] * i % mod;

    for (int k = max(0, x - m); k <= min(n, x); ++k) {
        int r = k;      // 红球数量
        int w = x - k;  // 白球数量
        if (w > m)
            continue;  // 白球数量不能超过总的白球数
        i64 perm =
            factorial[x] * inv(factorial[r]) % mod * inv(factorial[w]) % mod;
        total = (total + perm) % mod;
    }
    cout << total << endl;
    return 0;
}