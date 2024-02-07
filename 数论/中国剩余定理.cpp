/*https://www.luogu.com.cn/problem/P1495*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=25+10;
int a[N],m[N];

int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int crt(int n){
    int M = 1, ans = 0;
    for (int i = 1; i <= n; i++) M = M * m[i];
    for (int i = 1; i <= n; i++) {
        int k = M/m[i],x,y;
        exgcd(k, m[i], x, y);  //  k*x  = 1 mod m[i]
        ans = (ans + a[i]*k*x % M) % M;
    }
    return (ans % M + M) % M;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>m[i]>>a[i];
    cout<<crt(n)<<endl;  
 
    return 0;
}