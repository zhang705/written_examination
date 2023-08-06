#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<n-k+1;i++){
        string temp=s.substr(i,k);
        int count[26]={0};
        int j=0;
        while(j<temp.size()){
            count[temp[j]-'a']++;
            j++;
        }
        int flag=0;
        int m=0;
        while(m<26){
            if(count[m]%2!=0){
                flag=1;
                break;
            }
            m++;
        }
        if(flag==0)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}