/*https://www.luogu.com.cn/problem/P2758*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=2e3+10;
typedef pair<int,int>pp;
int f[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    for(int i=0;i<=n;++i)
        f[i][0]=i;
    for(int i=0;i<=m;++i)
        f[0][i]=i;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            f[i][j]=min(f[i-1][j],f[i][j-1])+1;
            f[i][j]=min(f[i][j],f[i-1][j-1]+(s[i-1]!=t[j-1]));
            //cerr<<i<<" "<<j<<" "<<f[i][j]<<endl;
        }
    }
    cout<<f[n][m]<<endl;

    return 0;
}