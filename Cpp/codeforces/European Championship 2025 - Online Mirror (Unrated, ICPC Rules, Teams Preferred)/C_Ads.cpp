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

void solve() {
    // cerr << "------------------------" << ln;
    int n, k;
    cin >> n >> k;
    multiset<i64> s;

    for (int i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        s.insert(x);
    }
    i64 ans = 0;

    auto it = s.begin();
    while (it != s.end()) {
        if (s.size() < 3) {
            break;
        }

        auto it2 = s.lower_bound(k - *it);
        if (it2 == s.begin()) {
            break;
        }
        it2--;
        if (it2 == it) {
            break;
        }

        if (s.size() == 3) {
            cout << ans << ln;
            return;
        }
        ans++;
        // cerr<<"1111 " << *it << " " << *it2 << " ";
        s.erase(it);
        s.erase(it2);
        auto itt = s.rbegin();
        // cerr << *std::next(itt).base() << ln;
        s.erase(std::next(itt).base());
        it = s.begin();
    }

    it = s.begin();
    while (it != s.end()) {
        if (s.size() == 1) {
            cout << ans << ln;
            return;
        }
        if (*it >= k) {
            ans++;
            // cerr << *it << ln;
            s.erase(it);
        } else if (s.size() == 2) {
            cout << ans << ln;
            return;
        } else {
            // cerr << *it << " " << *std::next(it) << ln;
            ans++;
            s.erase(it);
            auto itt = s.rbegin();
            s.erase(std::next(itt).base());
        }

        it = s.begin();
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
