/*https://www.luogu.com.cn/problem/P1886*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e6+10;
int a[N],q1[N],q2[N];
int n,k;
vector<int>res1,res2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    int hh=0,tt=0;
    for(int i=1;i<=n;++i){
        while(hh<tt&&q1[hh]+k<=i){
            ++hh;
        }
        while(hh<tt&&a[q1[tt-1]]<a[i]){
            tt--;
        }
        q1[tt]=i;
        ++tt;
        if(i>=k)res1.push_back(a[q1[hh]]);
    }
    hh=0,tt=0;
    for(int i=1;i<=n;++i){
        while(hh<tt&&q2[hh]+k<=i){
            ++hh;
        }
        while(hh<tt&&a[q2[tt-1]]>a[i]){
            tt--;
        }
        q2[tt]=i;
        ++tt;
        if(i>=k)res2.push_back(a[q2[hh]]);
    }
    for(auto &x:res2){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto &x:res1){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}