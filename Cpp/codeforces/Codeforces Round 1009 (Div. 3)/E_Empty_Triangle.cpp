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
    std::srand(std::time(0));
    int n;
    cin >> n;
    int x1, x2, x3;

    x1 = rand() % n + 1;

    do {
        x2 = rand() % n + 1;
    } while (x2 == x1);

    do {
        x3 = rand() % n + 1;
    } while (x3 == x1 || x3 == x2);

    while (1) {
        cout << "? " << x1 << " " << x2 << " " << x3 << ln;
        cout.flush();
        int p;
        cin >> p;

        if (p == 0) {
            cout << "! " << x1 << " " << x2 << " " << x3 << ln;
            cout.flush();
            return;
        } else {
            i64 i = rand() % 3 + 1;
            if (i == 1) {
                x1 = p;
            } else if (i == 2) {
                x2 = p;
            } else {
                x3 = p;
            }
        }
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
