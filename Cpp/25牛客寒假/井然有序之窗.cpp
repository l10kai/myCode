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

struct node {
    i64 l, r, x;
};

void solve() {
    int n;
    cin >> n;

    deque<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].x = i + 1;
    }

    sort(all(a), [](node &a, node &b) {
        if (a.l == b.l)
            return a.r < b.r;
        return a.l < b.l;
    });

    set<tuple<i64, i64, i64>> st;

    vector<i64> ans(n);

    for (int i = 1; i <= n; i++) {
        while (!a.empty() && a[0].l <= i) {
            st.insert({a[0].r, a[0].l, a[0].x});
            //a.erase(a.begin());
            a.pop_front();
        }
        if (st.empty()) {
            cout << -1 << ln;
            return;
        }
        auto [r, l, x] = *st.begin();
        st.erase(st.begin());
        if(r < i) {
            cout << -1 << ln;
            return;
        }
        ans[x - 1] = i;
    }

    for (auto x : ans)
        cout << x<< " ";
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
