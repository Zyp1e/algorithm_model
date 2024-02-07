/*https://www.luogu.com.cn/problem/P6175*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int n,m;
const int N=110,M=5e3+10;
ll w[N][N],d[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i!=j)w[i][j]=d[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;++i){
        int x,y,val;
        cin>>x>>y>>val;
        w[x][y]=d[x][y]=d[y][x]=w[y][x]=val;
    }
    ll ans=1e18;
    for(int k=1;k<=n;++k){
        for(int i=1;i<k;++i){
            for(int j=i+1;j<k;++j){
                ans=min(ans,d[i][j]+w[i][k]+w[k][j]);
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    if(ans!=1e18)cout<<ans<<endl;
    else cout<<"No solution."<<endl;
    return 0;
}