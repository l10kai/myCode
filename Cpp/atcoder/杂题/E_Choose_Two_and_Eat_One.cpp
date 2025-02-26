/*
最大生成树板子题
*/

#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    int get(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {  // 设x是y的祖先
        x = get(x), y = get(y);
        if (x == y)
            return false;
        fa[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
};
struct Tree {
    using TII = tuple<int, int, int>;
    int n;
    priority_queue<TII> ver;

    Tree(int n) {
        this->n = n;
    }
    void add(int x, int y, int w) {
        ver.emplace(w, x, y);  // 注意顺序
    }
    int kruskal() {
        DSU dsu(n);
        int ans = 0, cnt = 0;
        while (ver.size()) {
            auto [w, x, y] = ver.top();
            ver.pop();
            if (dsu.same(x, y))
                continue;
            dsu.merge(x, y);
            ans += w;
            cnt++;
        }
        assert(cnt < n - 1);  // 输入有误，建树失败
        return ans;
    }
};

i64 fpow(i64 a, i64 b, i64 mod) {
    i64 res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Tree tree(n);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (i == j)
                continue;
            tree.add(i, j ,
                     (fpow(a[i], a[j], m) + fpow(a[j], a[i], m)) % m);
        }

    cout << tree.kruskal() << endl;
    return 0;
}