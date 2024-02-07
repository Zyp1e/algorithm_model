/*https://www.acwing.com/problem/content/5/*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e3+10,M=2e3+10;
int f[M],g[M],q[M];
int n,m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        memcpy(g,f,sizeof f);
        int v,w,s;
        cin>>v>>w>>s;
        for(int j=0;j<v;++j){
            int hh=0,tt=0;
            for(int k=j;k<=m;k+=v){
                while(hh<tt&&q[hh]<k-s*v)hh++;
                if(hh<tt)f[k]=max(g[k],g[q[hh]]+(k-q[hh])/v*w);
                while(hh<tt&&g[k]>=g[q[tt-1]]+(k-q[tt-1])/v*w)--tt;
                q[tt]=k;
                ++tt;
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}