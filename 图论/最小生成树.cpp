/*https://www.acwing.com/problem/content/description/1142/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=1e2+10;
int g[N][N];
int vis[N],dis[N];
int n;
/*void prim(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&(t==-1||dis[j]<dis[t])) 
                t=j;
        vis[t]=true;
        res+=dis[t];
        for(int j=1;j<=n;j++)   
            dis[j]=min(dis[j],g[t][j]);
    }
    cout<<res<<endl;
}*/
int e[N*N],w[N*N],ne[N*N],h[N],idx;
void add(int a,int b,int c){
    e[++idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
}
typedef pair<int,int>pp;
priority_queue<pp,vector<pp>,greater<pp> >pq;
void prim(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    int res=0;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=true;
        res+=dis[u];
        for(int i=h[u];i!=-1;i=ne[i]){
            int v=e[i];
            if (!vis[v] && w[i] < dis[v]) {
                dis[v] = w[i];
                pq.push({dis[v], v});
            }
        }
    }
    cout<<res<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            add(i,j,x);
        }
            
    prim(1);
	
	return 0;
} 