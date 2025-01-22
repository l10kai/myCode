#include <iostream>
using namespace std;
const int N = 100010;
int st[N];
int top = -1;
int n;
int main() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        // 栈顶所在索引往后移动一格，然后放入x。
        if (s == "push") {
            int a;
            cin >> a;
            st[++top] = a;
        }

        // 往前移动一格
        if (s == "pop") {
            top--;
        }
        // 返回栈顶元素
        if (s == "query") {
            cout << st[top] << endl;
        }
        // 大于等于 0 栈非空，小于 0 栈空
        if (s == "empty") {
            cout << (top == -1 ? "YES" : "NO") << endl;
        }
    }
}
/*

5 3 1

idx = -1

arr[]

if(idx == -1) stack is empty


push(x) -> arr[++ idx] = x


x _ _ _ _ _

*/
