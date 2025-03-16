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

const int N = 4e4 + 10, K = 60;

int n, k, f[K][N], a[N], mp[N], pre[N];

struct node {
    int l, r, tag, val;
};

struct segmenttree {
#define ls  (p << 1)
#define rs  (p << 1 | 1)
#define mid ((t[p].l + t[p].r) >> 1)
    node t[N << 2];
    inline void pushup(int p) {
        t[p].val = max(t[ls].val, t[rs].val);
    }
    inline void updata(int p, int x) {
        t[p].val = t[p].val + x;
        t[p].tag = t[p].tag + x;
    }
    inline void pushdown(int p) {
        if (!t[p].tag)
            return;
        updata(ls, t[p].tag);
        updata(rs, t[p].tag);
        t[p].tag = 0;
    }
    inline void build(int p, int l, int r, int now) {
        t[p].l = l, t[p].r = r;
        if (l == r) {
            t[p].val = f[now][l - 1];
            return;
        }
        build(ls, l, mid, now), build(rs, mid + 1, r, now);
        pushup(p);
    }
    inline void modify(int p, int l, int r, int x) {
        if (l <= t[p].l && t[p].r <= r)
            return updata(p, x);
        pushdown(p);
        if (l <= mid)
            modify(ls, l, r, x);
        if (r > mid)
            modify(rs, l, r, x);
        pushup(p);
    }
    inline int query(int p, int l, int r) {
        if (l <= t[p].l && t[p].r <= r)
            return t[p].val;
        pushdown(p);
        int res = 0;
        if (l <= mid)
            res = max(res, query(ls, l, r));
        if (r > mid)
            res = max(res, query(rs, l, r));
        return res;
    }
    inline void clear() {
        memset(t, 0, sizeof(t));
    }
} s;

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = mp[a[i]] + 1;
        mp[a[i]] = i;
    }

    for (int i = 1; i <= k; i++) {
        s.clear();
        s.build(1, 1, n, i - 1);

        for (int j = 1; j <= n; j++) {
            s.modify(1, pre[j], j, 1);
            f[i][j] = s.query(1, 1, j);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
