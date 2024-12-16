#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

struct node {
    vector<i64> a;
    i64 idx;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<i64> a;
    vector<node> permutation;
    for (int i = 1; i <= n; i++) {
        a.push_back(i);
    }
    i64 ans = 0;
    i64 maxx = -1;

    do {
        i64 sum = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                i64 minn = 1e18;
                for (int k = j; k < j + i; k++) {
                    minn = min(minn, a[k]);
                }
                sum += minn;
            }
        }

        permutation.push_back({a, sum});

        if (maxx < sum) {
            maxx = sum;
            ans = 1;
        } else if (maxx == sum) {
            ans++;
        }
    } while (next_permutation(a.begin(), a.end()));

    sort(permutation.begin(), permutation.end(), [](node a, node b) {
        if (a.idx != b.idx)
            return a.idx > b.idx;
        return a.a < b.a;
    });

    for (auto [b, idx] : permutation) {
        for (auto x : b) {
            cout << x << " ";
        }
        cout << ln;
        cout << "idx: " << idx << ln;
    }

    cout << "ans and maxx: " << ans << " " << maxx << ln;

    return 0;
}
