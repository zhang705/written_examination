//计算一个字符串中长度为k的子串中，每个字符出现次数都是偶数的子串的个数
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

int main() {
    // 输入n和k，n代表字符串的长度，k代表子串的长度
    int n, k;
    cin >> n >> k;

    // 输入字符串s
    string s;
    cin >> s;

    // 初始化答案计数器为0
    int ans = 0;

    // 遍历字符串s的每个可能的子串，长度为k
    for (int i = 0; i < n - k + 1; i++) {
        // 提取子串temp
        string temp = s.substr(i, k);

        // 创建一个计数数组count，用于记录子串中每个字符的出现次数
        int count[26] = {0};

        // 统计子串中每个字符的出现次数
        int j = 0;
        while (j < temp.size()) {
            count[temp[j] - 'a']++;
            j++;
        }

        // 初始化标志位为0
        int flag = 0;

        // 检查计数数组中的每个字符出现次数是否为偶数
        int m = 0;
        while (m < 26) {
            if (count[m] % 2 != 0) {
                flag = 1;
                break;
            }
            m++;
        }

        // 如果标志位为0，表示子串中的每个字符出现次数都是偶数，将答案计数器加1
        if (flag == 0)
            ans++;
    }

    // 输出答案计数器的值
    cout << ans << endl;

    return 0;
}