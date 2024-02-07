/*https://www.acwing.com/problem/content/description/287/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=6e3+10;
int a[N],f[N][2],vis[N];
int e[N<<1],ne[N<<1],h[N],idx;
void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}
void dfs(int u,int fa){
    f[u][0]=0,f[u][1]=a[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int v=e[i];
        if(v!=fa){
            dfs(v,u);
            f[u][0]+=max(f[v][0],f[v][1]);
            f[u][1]+=f[v][0];
        }
    }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(h,-1,sizeof h);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
	    int l,k;
	    cin>>l>>k;
	    add(l,k);
	    add(k,l);
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<endl;
	return 0;
} 