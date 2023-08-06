#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main() {
    //第一行输入一个正整数，代表节点的数量
    int n;
    cin>>n;
    //接下来的n-1行，每行输入2个正整数u和v，代表节点u和节点v有一条边连接
    int u,v;
    vector<int> tree[n+1];
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    //最后一行输入一个x，代表删除节点的编号，删除这个节点之后，数变成了一个森林
    int x;
    cin>>x;
    //求删除节点x之后，森林中的连通块数量和每个连通块的大小
    //第一行输出一个正整数，代表连通块的数量
    int count=0;
    for(int i=1;i<=n;i++){
        if(i==x)
            continue;
        if(tree[i].size()==1)
            count++;
    }
    cout<<count<<endl;
    //第二行升序输出k个正整数ai，代表每个连通块的大小
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(i==x)
            continue;
        if(tree[i].size()==1){
            int temp=1;
            int j=0;
            while(j<tree[i].size()){
                if(tree[i][j]!=x){
                    temp++;
                }
                j++;
            }
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
