#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

typedef pair<long double, long double> pll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double n, M;
    cin >> n >> M;

    vector<pll> a(n);

    for (auto &[x, y] : a)
        cin >> x;
    for (auto &[x, y] : a)
        cin >> y;

    sort(a.begin(), a.end(), [&](pll x, pll y) {
        return x.first / x.second >= y.first / y.second;
    });

    long double ans = 0;

    for (auto [c, k] : a) {
        if (M >= k) {
            M -= k;
            ans += c * 100;
        } else {
            if (M < k) {
                ans += c * M / k * 100;
                break;
            }
        }
    }

    cout << fixed << setprecision(4) << ans << ln;

    return 0;
}