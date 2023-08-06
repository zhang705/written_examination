#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    //第一行输入两个正整数n和k，用空格隔开，代表字符串的长度和子串的长度
    int n,k;
    cin>>n>>k;
    //第二行输入n和正整数ai，代表数组
    int a[n];
    for(int p=0; p<n;p++){
        cin>>a[p];
    }
    //找到所有存在某元素出现的次数不小于数组大小的一半的子串，并输出满足条件子串的数量
    int ans=0;
    int i=0;
    while(i<n-k+1){
        int temp[k];
        int j=0;
        while(j<k){
            temp[j]=a[i+j];
            j++;
        }
        int count=0;
        int m = 0;
        while(m < k){
            int n=0;
            while(n<k){
                if(temp[m]==temp[n])  count++;
                n++;
            }
            m++;
        }
        if(count>=k/2)  ans++;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}