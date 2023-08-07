#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if(n == 0) {
        cout << k << endl;
    }

    string s;
    cin >> s;

    // 从左往右遍历字符串，找到第一个比k小的位置，插入k
    int i;
    for (i = 0; i < n; i++) {
        if (s[i] - '0' < k) {
            s.insert(i, 1, k + '0');
            break;
        }
    }

    // 如果遍历完整个字符串都没有找到比k小的位置，说明k是最大的，将其插入到字符串的末尾
    if (i == n) {
        s += to_string(k);
    }

    cout << s << endl;

    system("pause");
    return 0;
}