/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define lowbit(x) (x & (-x))

#define as  static_cast
#define fi  first
#define se  second
#define pb  push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

struct SegmentTree {
    int n;
    vector<vector<i64>> tree;

    SegmentTree(const vector<i64> &arr) {
        n = arr.size();
        tree.resize(n * 4);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<i64> &arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx].push_back(arr[left]);
            return;
        }
        int mid = (left + right) >> 1;
        build(arr, idx << 1, left, mid);
        build(arr, (idx << 1) | 1, mid + 1, right);
        merge(tree[idx << 1].begin(), tree[idx << 1].end(),
              tree[(idx << 1) | 1].begin(), tree[(idx << 1) | 1].end(),
              back_inserter(tree[idx]));
    }

    i64 query(int idx, int start, int end, int l, int r, i64 x, i64 y) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r) {
            auto lower = lower_bound(tree[idx].begin(), tree[idx].end(), x);
            auto upper = upper_bound(tree[idx].begin(), tree[idx].end(), y);
            return upper - lower;
        }
        int mid = (start + end) >> 1;
        return query(idx << 1, start, mid, l, r, x, y) +
               query((idx << 1) | 1, mid + 1, end, l, r, x, y);
    }

    i64 queryRange(int l, int r, i64 x, i64 y) {
        return query(1, 0, n - 1, l, r, x, y);
    }
};

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;

    vector<i64> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    SegmentTree st(a);
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += st.queryRange(i + 1, n - 1, sum - a[i] - y, sum - a[i] - x);
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
