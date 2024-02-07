/*https://www.acwing.com/problem/content/description/1083/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int l,r,k,b;
const int N=35;
int a[N],f[N][N];
int dfs(int pos,int cnt,int lead,int lim){
    if(!pos)return cnt==k;
    if(!lim&&f[pos][cnt]!=-1)return f[pos][cnt];
    int up=lim?a[pos]:b-1;
    int res=0;
    for(int i=0;i<=up;++i){
        if(i==0)res+=dfs(pos-1,cnt,i,lim&&i==a[pos]);
        else if(i==1){
            res+=dfs(pos-1,cnt+1,i,lim&&i==a[pos]);
        }else break;
    }
    if(!lim)f[pos][cnt]=res;
    return res;
}
int cal(int x){
    int cnt=0;
    memset(f,-1,sizeof f);
    while(x){
        a[++cnt]=x%b;
        x/=b;
    }
    return dfs(cnt,0,0,1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>l>>r>>k>>b;
	cout<<cal(r)-cal(l-1)<<endl;
	return 0;
} 