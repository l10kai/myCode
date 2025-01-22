#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
typedef pair<i64, i64> pll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pll> a(n);
    i64 l, r;
    cin >> l >> r;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](const pll &a, const pll &b) {
        return a.first * a.second < b.first * b.second;
    });

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans = max(ans, l / a[i].second);
        l = l * a[i].first;
    }

    cout << ans << '\n';

    return 0;
}