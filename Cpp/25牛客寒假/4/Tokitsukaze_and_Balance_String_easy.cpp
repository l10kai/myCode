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
const i64 mod = 1e9 + 7;
void solve() {
    i64 n;
    cin >> n;
    
    string str;
    cin >> str;


    vector<i64> tmp;
    for (int i = 0; i < n; i++) {
        if (str[i] == '?')
            tmp.pb(i);
    }

    i64 ans = 0;

    auto check = [&](string &s) {
        int num1 = 0, num2 = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0' && s[i + 1] == '1')
                num1++;
            if (s[i] == '1' && s[i + 1] == '0')
                num2++;
        }
        return num1 == num2;
    };

    auto val = [&](string &s) {
        i64 res = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            s[i] = (ch == '0' ? '1' : '0');
            if (check(s))
                res++;
            s[i] = ch;
        }
        return res;
    };

    for (int i = 0; i < (1 << tmp.size()); i++) {
        for (int j = 0; j < tmp.size(); j++) {
            str[tmp[j]] = ((i >> j) & 1) ? '1' : '0';
        }
        ans = (ans + val(str)) % mod;
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
