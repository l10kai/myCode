#include <bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = int64_t;
using u64 = uint64_t;

const char &ln = '\n';

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    char ch1, ch2;
    int n;
    cin >> n >> ch1 >> ch2;
    cin >> str ;

    for(auto &ch : str) {
        if(ch != ch1) ch = ch2;
    }

    cout << str << ln;

    return 0;
}
