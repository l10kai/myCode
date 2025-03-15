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
    string str;
    i64 cnt, posion;
};

void solve() {
    vector<node> v(6);
    vector<string> ans;
    for (auto &[str, cnt, posion] : v) {
        cin >> str >> cnt >> posion;
    }

    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                bool flag = false;
                for (auto &[str, cnt, posion] : v) {
                    // vector<bool> bl1(3, false), bl2(3, false);
                    i64 cot1 = 0, cot2 = 0;
                    if (i == str[0])
                        cot2++;
                    if (j == str[1])
                        cot2++;
                    if (k == str[2])
                        cot2++;

                    for (int l = 0; l < 3; l++) {
                        if (str[l] == i || str[l] == j || str[l] == k) {
                            cot1++;
                        }
    
                    }

                    // cerr << cot1 << ' ' << cot2 << ln;
                    if (cot1 != cnt || cot2 != posion) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    ans.pb({(string) "" + i + j + k});
                }
            }
        }
    }

    cout << ans.size() << ln;
    for (auto &i : ans) {
        cout << i << ln;
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
