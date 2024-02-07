/*https://www.acwing.com/problem/content/854/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m;
const int N=2e3+10,M=1e4+10,inf=0x3f3f3f3f;
int e[M],w[M],nex[M],h[N],idx;
int dis[N],vis[N],cnt[N];
void add(int a,int b,int c){
    e[++idx]=b;
    w[idx]=c;
    nex[idx]=h[a];
    h[a]=idx;
}
queue<int>q;
bool spfa(){
    for(int i=1;i<=n;++i){
        dis[i]=inf;
        vis[i]=1;
        q.push(i);
    }
    dis[1]=0;
    
    while(q.size()){
        int u=q.front();
        vis[u]=0;
        q.pop();
        for(int i=h[u];i!=-1;i=nex[i]){
            int v=e[i];
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)return true;//true表示有负环
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
                /*
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]=cnt[u]+1;
                    if(cnt[v]>=n)return true;//true表示有负环
                }
                */
            }
        }
    }
    return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<=n+5;++i)h[i]=-1;
	for(int i=1;i<=m;++i){
	    int a,b,c;
	    cin>>a>>b>>c;
	    add(a,b,c);
	}
	if(!spfa()){
	    cout<<"No"<<endl;
	}else cout<<"Yes"<<endl;
	
	return 0;
} 