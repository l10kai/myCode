#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

bool is_prime(i64 x) {
    if (x < 2)
        return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

signed main() {
    int l, r;
    cin >> l >> r;
    vector<i64> primes;
    for (int i = l; i <= r; i++) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    i64 ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size(); j++) {
            for (int k = j + 1; k < primes.size(); k++) {
                if (is_prime(primes[i] * primes[j] + primes[k]) &&
                    is_prime(primes[i] * primes[k] + primes[j]) &&
                    is_prime(primes[j] * primes[k] + primes[i])) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
