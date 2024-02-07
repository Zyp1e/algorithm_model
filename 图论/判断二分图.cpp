/*https://www.acwing.com/problem/content/862/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=2e5+10;
int color[N];
int e[N],h[N],nex[N],idx;//无向边，边的实际最大数量应该定义为点的两边
void add(int a,int b){
	e[++idx]=b,nex[idx]=h[a],h[a]=idx;
}
bool dfs(int u,int f){
	color[u]=f;
	
	for(int i=h[u];i!=-1;i=nex[i]){
		int v=e[i];
		//cout<<u<<" "<<v<<" "<<color[v]<<" "<<f<<endl;
		if(!color[v]){
			if(!dfs(v,3-f))return false;
		}else if(color[v]==f)return false;
	}
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(h,-1,sizeof h);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	bool flag=true;
	for(int i=1;i<=n;++i){
		if(!color[i]){
			if(!dfs(i,1)){
				flag=false;
				break;
			}
		}
	}
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
} 