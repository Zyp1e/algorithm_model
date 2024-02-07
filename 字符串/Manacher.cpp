/*https://www.luogu.com.cn/problem/P3805*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=11e6+10;
string str,ss;
int d[N*2],ans=1;//ans包括#
inline void getd(string s){
    d[1]=1;
    for(int i=2,l,r=1;i<s.size();++i){
        if(i<=r)d[i]=min(d[r-i+l],r-i+1);
        while(s[i-d[i]]==s[i+d[i]])d[i]++;
        if(i+d[i]-1>r)l=i-d[i]+1,r=i+d[i]-1;
        ans=max(ans,d[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    ss+='$';
    ss+='#';
    for(int i=0;i<str.size();++i){
        ss+=str[i];
        ss+='#';
    }
    getd(ss);
    cout<<ans-1<<endl;

    return 0;
}