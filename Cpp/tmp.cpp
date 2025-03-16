#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
    struct tuple_hash {
        size_t operator()(const tuple<string, int, int, int, bool> &t) const {
            auto &[s, x1, x2, x3, b] = t;
            const auto h1 = std::hash<string>{}(s);
            const auto h2 = std::hash<int>{}(x1);
            const auto h3 = std::hash<int>{}(x2);
            const auto h4 = std::hash<int>{}(x3);
            const auto h5 = std::hash<bool>{}(b);
            size_t res = 0;
            auto combine = [&](size_t h) {
                res ^= h + 0x9e3779b97f4a7c15ULL + (res << 6) + (res >> 2);
            };
            combine(h1);
            combine(h2);
            combine(h3);
            combine(h4);
            combine(h5);
            return res;
        }
    };
public:
    int beautifulNumbers(int l, int r) {
        string str_l = to_string(l - 1), str_r = to_string(r);
        unordered_map<tuple<string, int, int, int, bool>, int, tuple_hash> mp;

        function<int(string, int, int, int, bool)> dfs =
            [&](string str, int num, int mul, int bits, bool limited) {
                if (mp.count({str, num, mul, bits, limited}))
                    return mp[{str, num, mul, bits, limited}];

                if (bits >= str.size()) {
                    if (num == 0)
                        return 0;
                    if (mul % num == 0) {
                        return 1;
                    }
                    return 0;
                }

                int ans = 0;

                if (limited) {
                    for (int i = 0; i <= str[bits] - '0'; i++) {
                        if (i == 0 && num == 0) {
                            ans += dfs(str, num, mul, bits + 1, false);
                            continue;
                        }
                        if (i == str[bits] - '0') {
                            ans += dfs(str, num + i, mul * i, bits + 1, true);
                            continue;
                        }

                        ans += dfs(str, num + i, mul * i, bits + 1, false);
                    }
                } else {
                    for (int i = 0; i <= 9; i++) {
                        if (i == 0 && num == 0) {
                            ans += dfs(str, num, mul, bits + 1, false);
                            continue;
                        }
                        ans += dfs(str, num + i, mul * i, bits + 1, false);
                    }
                }
                mp[{str, num, mul, bits, limited}] = ans;
                return ans;
            };
        int x = dfs(str_r, 0, 1, 0, true);
        int y = dfs(str_l, 0, 1, 0, true);
        return x - y;
    }
};

int main() {
    Solution s;
    int l, r;
    cin >> l >> r;
    cout << s.beautifulNumbers(l, r) << endl;
    return 0;
}