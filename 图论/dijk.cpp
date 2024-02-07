/*https://www.acwing.com/problem/content/description/851/*/
#include<bits/stdc++.h>
#define int long long
/*------------------如果定义为long long则memset(dis,0x3f,sizeof dis)之后的数组每个元素都变为0x3f3f3f3f3f3f3f3f,8个3f*/
#define endl '\n' 
using namespace std;
int n,m;
const int N=510,M=1e5+10;
int e[M],ne[M],w[M],h[N],idx;
int dis[N],vis[N];
typedef pair<int,int> pp;
priority_queue<pp,vector<pp>,greater<pp> > q;
void add(int a,int b,int c){
    e[++idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx;
}
void dijk(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    q.push(pp(0,s));
    while(!q.empty()){
        //cout<<dis[n]<<endl;
        int w1=q.top().first,u=q.top().second;
        //cout<<u<<" "<<w1<<endl;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i!=-1;i=ne[i]){
            int v=e[i];
            if(dis[v]>w1+w[i]){
                dis[v]=w1+w[i];
                q.push(pp(dis[v],v));
            }
        }
    }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(h,-1,sizeof h);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
	    int u,v,w;
	    cin>>u>>v>>w;
	    add(u,v,w);
	}
	
	dijk(1);
	//cout<<0x3f3f3f3f<<endl;
	if(dis[n]==0x3f3f3f3f3f3f3f3f)cout<<-1<<endl;
	else cout<<dis[n]<<endl;
	return 0;
} 