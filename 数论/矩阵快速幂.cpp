/*https://www.luogu.com.cn/problem/P3390*/
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10,mod=1e9+7;
typedef pair<int,int>pp;
typedef long long LL;
int a[N];
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
                t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % mod;
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
    matrix A,ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin>>x;
            A.c[i][j]=x;
        }
    }
    ans = qpow(A, k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<ans.c[i][j]<<" \n"[j==n];
        }
    }
    
    return 0;
}