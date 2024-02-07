/*https://atcoder.jp/contests/dp/tasks/dp_r*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=50+10;
typedef pair<int,int>pp;
typedef long long LL;
 
const int P = 1e9+7;
struct matrix {
    LL c[101][101];
    matrix() {
        memset(c, 0, sizeof(c));
    }
};

LL n, k;

matrix operator*(matrix &x, matrix &y) {
    matrix t;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j])%P;
            }
        }
    }
    return t;
}

matrix qpow(matrix A,LL k) {
    matrix res;
    for (int i = 1; i <= n; i++) {
        res.c[i][i] = 1;
    }
    while (k) {
        if (k & 1) {
            res = res * A;
        }
        A = A * A;
        k >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    matrix f,g,tt;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            LL x;
            cin>>x;
            g.c[i][j]=x;
        }
    }   
    for(int i=1;i<=n;++i)f.c[1][i]=1;
    tt=qpow(g,k);
    f=f*tt;
    LL ans=0;
    for(int i=1;i<=n;++i)ans=(ans+f.c[1][i])%P;
    cout<<ans<<endl;
    
    return 0;
}