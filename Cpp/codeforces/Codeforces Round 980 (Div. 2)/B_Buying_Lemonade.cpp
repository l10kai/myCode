/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define lowbit(x) (x & (-x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

// #define cin fin
// #define cout fout
// std::ifstream fin("E:/Cpp/duipai/in.txt");
// std::ofstream fout("E:/Cpp/duipai/out.txt");

using namespace std;
using f64 = double;
using i64 = long long;
using u64 = unsigned long long;
using f128 = long double;

const char &ln = '\n';

void solve() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n);
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    for (auto &x : a) {
        cin >> x;
        pq.push(x);
    }
    sort(all(a));
    i64 times = 0, tmp = 0, old = 0;
    while (!pq.empty()) {
        i64 x = pq.top();
        pq.pop();
        x -= old;
        if (x == 0) {
            tmp++;
            continue;
        }

        if (k > x * (n - tmp)) {
            k -= x * (n - tmp);
            times += x * (n - tmp);
            old += x;
            tmp++;
        } else {
            i64 t = floor((k * 1.0) / (n - tmp));
            k = k % (n - tmp);
            times += t * (n - tmp) + k + tmp;
            break;
        }
    }

    cout << times << ln;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
