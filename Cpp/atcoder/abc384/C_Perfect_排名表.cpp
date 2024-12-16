/*
 __       __  .__   __.  __  ___
|  |     |  | |  \ |  | |  |/  /
|  |     |  | |   \|  | |  '  /z
|  |     |  | |  . `  | |    <
|  `----.|  | |  |\   | |  .  \
|_______||__| |__| \__| |__|\__\
*/
#include <bits/stdc++.h>
#include <ostream>
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
namespace std {
    std::ostream &endl(std::ostream &os) {
        return os.put('\n');
    }
}

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

const static std::vector<std::string> table{
    "ABCDE", "BCDE", "ACDE", "ABDE", "ABCE", "ABCD", "CDE", "BDE",
    "ADE",   "BCE",  "ACE",  "BCD",  "ABE",  "ACD",  "ABD", "ABC",
    "DE",    "CE",   "BE",   "CD",   "AE",   "BD",   "AD",  "BC",
    "AC",    "AB",   "E",    "D",    "C",    "B",    "A",
};
void solve() {
    std::vector<std::pair<i64, std::string>> answer_table(table.size());
    std::unordered_map<char, i64> mp;
    for (char c = 'A'; c <= 'E'; ++c)
        std::cin >> mp[c];
    for (int i = 0; i < table.size(); ++i)
        answer_table[i] = {0, table[i]};
    for (auto &[score, line] : answer_table)
        for (const auto &c : line) {
            score -= mp[c];
        }
    std::sort(answer_table.begin(), answer_table.end());
    for (const auto &[score, line] : answer_table)
        std::cout << line << std::endl;
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
