/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#define mem(x, y) memset(x, y, sizeof(x))
#define all(x)    x.begin(), x.end()
#define rall(v)   v.rbegin(), v.rend()
#define sqr(x)    ((x) * (x))
#define as        static_cast
#define fi        first
#define se        second
#define pb        push_back
#define ppb       pop_back
#define pii       pair<int, int>
#define pll       pair<i64, i64>

using namespace std;
using i64 = long long;
const char &ln = '\n';

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n + 10);

    for (int i = 1;i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++) {
        if(a[a[i]] == i){
            cout << "2" <<ln;
            return;

        }
    }

    cout <<"3" <<ln;


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
    return 0;
}
