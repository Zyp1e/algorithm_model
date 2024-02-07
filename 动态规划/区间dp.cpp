/*https://www.luogu.com.cn/problem/P1775*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=310;
int a[N],s[N],f[N][N],p[N][N];
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        f[i][i]=0;
        p[i][i]=i;
    }
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            for(int k=p[i][j-1];k<=p[i+1][j];++k){
                if(f[i][j]>f[i][k]+f[k+1][j]+s[j]-s[i-1]){
                    f[i][j]=f[i][k]+f[k+1][j]+s[j]-s[i-1];
                    p[i][j]=k;
                }
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}