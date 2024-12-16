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

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';
namespace std {
    std::ostream &endl(std::ostream &os) {
        return os.put('\n');
    }
}

// lowbit(4) => 4
// log2(4) => 2
// 4 >> 2 => 1
int f(int x) {
    return x >> std::__lg(lowbit(x));
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a)
        std::cin >> i;
    i64 answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            answer += f(a[i] + a[j]);
    std::cout << answer << std::endl;
}
// #define T_CASE

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
#ifdef T_CASE
    std::cin >> t;
#endif

    while (t--) {
        solve();
    }
    // fin.close();
    // fout.close();
    return 0;
}
