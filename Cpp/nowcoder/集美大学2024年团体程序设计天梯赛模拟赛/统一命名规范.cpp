/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <cctype>
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
    int n;
    string str;
    cin >> n >> str;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        vector<string> v;
        string tmp;

        s[0] = tolower(s[0]);
        for (int j = 0; j < s.size(); j++) {
            if (islower(s[j])) {
                tmp += s[j];
            } else if (s[j] == '_') {
                v.pb(tmp);
                tmp = "";
            } else {
                v.pb(tmp);
                tmp = s[j] + 'a' - 'A';
            }
        }

        if (tmp.size())
            v.pb(tmp);

        if (str == "Camel") {
            for (auto &i : v) {
                i[0] = toupper(i[0]);
            }
            v[0][0] = tolower(v[0][0]);
            for (int j = 0; j < v.size(); j++) {
                cout << v[j];
            }
        } else if (str == "Pascal") {
            for (auto &i : v) {
                i[0] = toupper(i[0]);
            }
            for (int j = 0; j < v.size(); j++) {
                cout << v[j];
            }
        } else {
            for (int j = 0; j < v.size(); j++) {
                cout << v[j] << (j == v.size() - 1 ? "" : "_");
            }
        }

        cout << ln;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    //  cout << char('B' + 'a'- 'A') << ln;
    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
