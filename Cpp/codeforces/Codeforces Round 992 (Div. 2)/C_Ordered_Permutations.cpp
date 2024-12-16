#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    i64 n, k;
    cin >> n >> k;

    if (n - 1 < log2(k--)) {
        cout << -1 << ln;
        return;
    }
    vector<i64> ans(n);
    i64 num = 1;
    i64 l = 0, r = n - 1;

    for (i64 i = n - 2; i >= 0; i--) {
        // cerr << "k i:" << k << " " << i << ln;

        if(i >= 63) {
            ans[l++] = num++;
            continue;
        }

        if ((k >> i) & 1ll ) {
            // cerr << i << " " << num << ln;
            ans[r--] = num++;
        } else
            ans[l++] = num++;
    }
    for (auto x : ans) {
        if (x != 0)
            cout << x << " ";
        else
            cout << num << " ";
    }
    cout << ln;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
