#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

typedef pair<int, int> pii;

const int N = 3e6 + 10;

int primes[N], cnt;  // primes[]存储所有素数
bool st[N];          // st[x]存储x是否被筛掉

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    get_primes(ceil(sqrt(n)));
    i64 ans = 0;


    for (int i = 0; i < cnt; i++) {
        if (pow(primes[i], 8) > n) {
            break;
        } else
            ans++;
    }
    for (int i = 0; i < cnt; i++) {
        i64 x = primes[i];
        if (x * x > n) {
            break;
        }

        i64 l = i, r = cnt - 1;

        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if ((double)primes[mid] * x <= sqrt(n)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (l - i > 0) {
            //cerr << "l = " << l << " i = " << i << ln;
            ans += l - i;
        }
    }
  //  cerr << "sqrt(n) = " << sqrt(n) << ln;
    cout << ans << ln;

    return 0;
}
