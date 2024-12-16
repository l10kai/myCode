#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, R;
    cin >> n >> R;

    for (int i = 0; i < n; i++) {
        char ch;
        int x;
        cin >> ch >> x;

        if (ch == '1') {
            if (R >= 1600 && R <= 2799)
                R += x;
        } else {
            if (R >= 1200 && R <= 2399)
                R += x;
        }
    }

    cout << R << ln;

    return 0;
}
