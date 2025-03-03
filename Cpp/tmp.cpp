#include <bits/stdc++.h>

using namespace std;

void printBinary(int num) {
    std::bitset<8> binary(num);
    std::cout << binary.to_string();
}

signed main() {
    string str ="avafasdfasdgadfgnjklfbadjk";
    
    count(str.begin(), str.end(), 'a');
    return 0;
}