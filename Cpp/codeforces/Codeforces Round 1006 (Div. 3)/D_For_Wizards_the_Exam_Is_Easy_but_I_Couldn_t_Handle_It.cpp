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

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<tuple<int, int, int>> b(n);
    for (int i = 0; i < n; i++) {
        i64 idx = -1, less = 0, greater = 0, sum = 0;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                less++;
            } else if(a[j] > a[i]) {
                greater++;
            }

            if (sum < (less - greater)) {
                sum = less - greater;
                idx = j;
            }

            b[i] = {sum, idx, i};
        }
    }

    sort(rall(b));

    auto [sum, idx, i] = b[0];
    if (sum == 0) {
        cout << "1 1" << ln;
        return;
    }

    cout << i + 1 << " " << idx + 1 << ln;
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
