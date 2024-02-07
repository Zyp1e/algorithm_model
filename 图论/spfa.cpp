/*https://www.acwing.com/problem/content/description/853/*/
#include<bits/stdc++.h>
#define int long long
/*------------------如果定义为long long则memset(dis,0x3f,sizeof dis)之后的数组每个元素都变为0x3f3f3f3f3f3f3f3f,8个3f*/
#define endl '\n' 
#define endl '\n' 
using namespace std;
int n,m;
const int N=1e5+10;
int e[N],w[N],ne[N],h[N],idx;
int vis[N],dis[N];
void add(int a,int b,int c){
    e[++idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx;
}
queue<int>q;
void spfa(int s){
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=h[u];i!=-1;i=ne[i]){
            int v=e[i];
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
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
	    int a,b,c;
	    cin>>a>>b>>c;
	    add(a,b,c);
	}
	spfa(1);
	if(dis[n]==0x3f3f3f3f3f3f3f3f)cout<<"impossible"<<endl;
	else cout<<dis[n]<<endl;
	return 0;
} 