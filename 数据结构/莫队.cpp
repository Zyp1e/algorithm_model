/*http://oj.daimayuan.top/course/15/problem/768*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
//#define endl '\n'
const int N=5e4+10,B=500;
int n,m;
int a[N];
int tmp;
int cnt[N],ans[N],bot[N];
array<int,3>que[N];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
bool cmp(array<int,3>a,array<int,3>b){
    int C=a[0]/B;
    if(C!=b[0]/B)return C<b[0]/B;
    return C%2?a[1]>b[1]:a[1]<b[1];
}
void add(int x){
    tmp+=cnt[a[x]];
    cnt[a[x]]++;
}
void del(int x){
    cnt[a[x]]--;
    tmp-=cnt[a[x]];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i){
        int l,r;
        cin>>l>>r;
        que[i]={l,r,i};
        bot[i]=(r-l)*(r-l+1)/2;
    }
    sort(que+1,que+m+1,cmp);
    int l=1,r=0;
    for(int i=1;i<=m;++i){
        while(r<que[i][1])++r,add(r);
        while(l>que[i][0])--l,add(l); 
        while(r>que[i][1])del(r),--r;
        while(l<que[i][0])del(l),++l;
        ans[que[i][2]]=tmp;
    }
    for(int i=1;i<=m;++i){
        int g=gcd(ans[i],bot[i]);
        cout<<ans[i]/g<<'/'<<bot[i]/g<<endl;
    }
    return 0;
}