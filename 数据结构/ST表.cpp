/*https://www.luogu.com.cn/problem/P3865*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+10;
int a[N];
int n,m;
int maxn[N][18];
int log_2[N];
void init()
{
    for(int i=1;i<=n;++i)maxn[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<j-1)][j-1]);
        }
    }
    for(int i=2;i<=n;++i){
        log_2[i]=log_2[i>>1]+1;
    }
}
int query(int l,int r){
    int k=log_2[r-l+1];
    return max(maxn[l][k],maxn[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    init();
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}