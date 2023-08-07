#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // 输入论文的数量

    unordered_map<string, int> authorScores;  // 用于存储作者名字和得分的哈希表

    for (int i = 0; i < n; i++) {
        int numAuthors;
        cin >> numAuthors;  // 输入每篇论文的作者数量

        vector<string> authors(numAuthors);
        for (int j = 0; j < numAuthors; j++) {
            cin >> authors[j];  // 输入每个作者的名字

            // 如果该作者在哈希表中不存在，将其初始得分设为0
            if (authorScores.find(authors[j]) == authorScores.end()) {
                authorScores[authors[j]] = 0;
            }
        }

        // 按照得分规则给作者加分
        int score = 3;
        for (const string& author : authors) {
            authorScores[author] += score;
            score--;
        }
    }

    // 对作者名字进行排序
    vector<string> sortedAuthors;
    for (const auto& entry : authorScores) {
        sortedAuthors.push_back(entry.first);
    }
    sort(sortedAuthors.begin(), sortedAuthors.end());

    // 输出每个作者的名字及得分
    for (const string& author : sortedAuthors) {
        cout << author << " " << authorScores[author] << endl;
    }

    system("pause");
    return 0;
}