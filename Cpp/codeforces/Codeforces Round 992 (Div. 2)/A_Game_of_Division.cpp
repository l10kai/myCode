#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (auto &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        bool flag = false;

        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (abs(a[i] - a[j]) % k == 0) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << "YES" << ln << i + 1 << ln;
            return;
        }
    }

    cout << "NO" << ln;
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
