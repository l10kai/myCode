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
    int n;
    cin >> n;

    vector<int> a(n);
    i64 num = 0, num1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1)
            num++;
        if (a[i] == 0)
            num1++;
    }
    if(n == 1 && a[0] == -1){
        cout << "Bob" << ln;
        return;
    }
    if (num == 0 || num > 1) {
        cout << "Alice" << ln;
        return;
    }

    if (a[0] == -1 || a[n - 1] == -1) {
        cout << "Alice" << ln;
        return;
    }
    i64 idx = 0;
    while (a[idx] != -1) {
        idx++;
    }
    if (idx == n - idx - 1) {
        cout << "Bob" << ln;

    } else {
        cout << "Alice" << ln;
    }
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
