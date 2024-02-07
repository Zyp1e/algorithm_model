#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=310+10;
typedef pair<int,int>pp;
int a[N],cnt[4];
double f[N][N][N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(9);
    int n;
    cin>>n;
    f[0][0][0]=0;
    for(int i=1;i<=n;++i)cin>>a[i],cnt[a[i]]++;
    for(int k=0;k<=n;++k){
        for(int j=0;j<=n;++j){
            for(int i=0;i<=n;++i){
                if(i||j||k){
                    int d=i+j+k;
                    if(i)f[i][j][k]+=f[i-1][j][k]*i/d;
                    if(j)f[i][j][k]+=f[i+1][j-1][k]*j/d;
                    if(k)f[i][j][k]+=f[i][j+1][k-1]*k/d;
                    f[i][j][k]+=1.0*n/d;
                }
            }
        }
    }
    cout<<f[cnt[1]][cnt[2]][cnt[3]]<<endl;

    return 0;
}