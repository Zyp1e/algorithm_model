/*https://www.luogu.com.cn/problem/P4777*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
int a[N],b[N];
int n;
int mul(int a,int b,int mod)
{
    int res=0;
    while(b>0)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int excrt(){
    int x,y,k;
    int M=b[1],ans=a[1];
    for(int i=2;i<=n;++i){
        int aa=M,bb=b[i],c=(a[i]-ans%bb+bb)%bb;
        int d=exgcd(aa,bb,x,y),bd=bb/d;
        if(c%d!=0)return -1;
        //x=x%bd*(int)(c/d)%bd;
        x=mul(x,c/d,bd);
        ans+=x*M;
        M*=bd;
        ans=(ans%M+M)%M;
    }
    return (ans%M+M)%M;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;++i)cin>>b[i]>>a[i];
    cout<<excrt()<<endl;

    return 0;
}