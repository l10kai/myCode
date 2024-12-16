#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::unordered_set<i64> mp;
    i64  n, S;
    cin >> n >> S;

    vector<i64> a(n);
    for (auto & i : a)
        std::cin >> i;
    S %= std::accumulate(a.begin(), a.end(), 0ll);
    if (S == 0) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    a.insert(a.end(), a.begin(), a.end());
    vector<i64> s(a.size() + 1);
    std::partial_sum(a.begin(), a.end(), s.begin() + 1);
    for (auto &sum : s) {
        if (mp.contains(sum)) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        mp.emplace(sum + S);
    }
    std::cout << "No" << std::endl;
    return 0;
}
