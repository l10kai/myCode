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
    i64 n;
    cin >> n;
    string str;
    cin >> str;

    vector<i64> pre_u_num(n);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            pre_u_num[i] = (str[i] == 'u');
            continue;
        }
        pre_u_num[i] = pre_u_num[i - 1] + (str[i] == 'u');
    }
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (str.substr(i, 8) == "uwawauwa") {
            if(i >= 2)
            ans += pre_u_num[i - 2];
        }
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
