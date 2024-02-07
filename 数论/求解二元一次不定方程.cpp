/*https://www.luogu.com.cn/problem/P5656*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
int a[N];
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x,y;
    int d=exgcd(a,b,x,y);
    if(c%d)cout<<-1<<endl;
    else {//ceil向上取整
        x*=c/d,y*=c/d;
        int p=b/d,q=a/d,k;//a*(x+p)+b*(y-q)=c,a*x+b*y=c,解得p=b*q/a,
        //又因为p,q为正整数,所以b*q=lcm(a,b)=a*b/d,可求得pq
        if(x<0)k=ceil((1.0-x)/p),x+=p*k,y-=q*k;//x+k*p>=1,将x升到最小正整数
        else k=(x-1)/p,x-=p*k,y+=q*k;//将x缩到最小正整数
        if(y>0){
            cout<<(y-1)/q+1<<" "<<x<<" "<<(y-1)%q+1<<" "<<x+(y-1)/q*p<<" "<<y<<endl;
        }else {//无正整数解
            cout<<x<<" "<<y+q*(int)ceil((1.0-y)/q)<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)	solve();
    return 0;
}