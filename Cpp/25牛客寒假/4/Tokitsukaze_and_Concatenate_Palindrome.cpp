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
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    auto remove = [&](string &a, string &b) {
        map<char, int> mpa, mpb;
        for (auto &ch : a) {
            mpa[ch]++;
        }
        for (auto &ch : b) {
            mpb[ch]++;
        }

        for (auto &[ch, cnt] : mpa) {
            if (mpb.count(ch)) {
                int mn = min(cnt, mpb[ch]);
                mpa[ch] -= mn;
                mpb[ch] -= mn;
            }
        }

        string reta, retb;

        for (auto &[ch, cnt] : mpa) {
            if (cnt > 0) {
                reta += string(cnt, ch);
            }
        }

        for (auto &[ch, cnt] : mpb) {
            if (cnt > 0) {
                retb += string(cnt, ch);
            }
        }
        a = reta;
        b = retb;
    };

    remove(a, b);

    auto remove2 = [&](string &s) {
        map<char, int> mp;
        for (auto &ch : s) {
            mp[ch]++;
        }
        string ret;
        for (auto &[ch, cnt] : mp) {
            if (cnt % 2 == 1) {
                ret.pb(ch);
            }
        }
        s = ret;
    };

    auto cal = [&](string &s) {
        map<char, int> mp;
        for (auto &ch : s) {
            mp[ch]++;
        }
        i64 res = 0;
        for (auto &[ch, cnt] : mp) {
            res += cnt / 2;
        }
        return res;
    };

    if (a.size() < b.size()) {
        swap(a, b);
    }
    // cerr << "a = " << a << " b = " << b << ln;
    if (b.empty()) {
        remove2(a);

        cout << a.size() / 2 << ln;
    } else {
        i64 num = cal(a);
        i64 add = a.size() - ceil((a.size() + b.size()) * 1.0 / 2);
        add = add > 0 ? add : 0;
        i64 ans = (a.size() + b.size()) / 2;
        ans -= min(add, num);
        cout << (ans < 0 ? 0 : ans) << ln;
    }

    // cerr << "a.size() = " << a.size() << " b.size() = " << b.size() << ln;
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
