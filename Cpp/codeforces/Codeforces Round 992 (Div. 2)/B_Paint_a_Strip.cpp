#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    double n;
    cin >> n;

    i64 r = 1, ans = 1;
    while (r < n) {
        ans++;
        r = 2 * (r + 1);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
