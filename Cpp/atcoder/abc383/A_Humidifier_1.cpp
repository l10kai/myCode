#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

typedef pair<int, int> pii;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    i64 ans = 0, now = 0;

    for (auto [x, y] : a) {
        ans -= x - now;
        if (ans < 0) {
            ans = 0;
        }
        now = x;
        ans += y;
    }

    cout << ans << ln;

    return 0;
}
