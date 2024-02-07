/*http://oj.daimayuan.top/course/23/problem/943*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=1e5+10;
int n,m,idx=0;
int dfn[N],low[N];
bool ins[N];
vector<int>vec[N];
stack<int>stk;
vector<vector<int> >res;
void dfs(int u){
	dfn[u]=low[u]=++idx;
	ins[u]=1;
	stk.push(u);
	for(auto v:vec[u]){
		if(!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}else{
			if(ins[v])low[u]=min(dfn[v],low[u]);
		} 
	}
	// for(auto v:vec[u]){
	// 	if(!dfn[v])dfs(v);
	// 	if(ins[v])low[u]=min(low[u],low[v]);
	// }
	if(dfn[u]==low[u]){
		vector<int>temp;
		while(1){
			int v=stk.top();
			temp.push_back(v);
			ins[v]=0;
			stk.pop();
			if(u==v)break;
		}
		sort(temp.begin(),temp.end());
		res.push_back(temp);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
		if(!dfn[i])dfs(i);
	}
	sort(res.begin(),res.end());
	for(auto x:res){
		for(auto y:x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return 0;
} 