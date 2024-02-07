/*https://www.luogu.com.cn/problem/P5905*/
#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3e3+10, M=6e3+10,inf=0x3f3f3f3f,INF=1e9;
int e[N*N],w[N*N],nex[N*N],h[N],idx;
int n,m;
ll vis[N],dis[N],d[N];
void add(int a,int b,int c){
    e[++idx]=b;
    w[idx]=c;
    nex[idx]=h[a];
    h[a]=idx;
}
queue<int>q;
void spfa(int s){
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    d[s]=0;
    vis[s]=1;
    q.push(s);
    
    while(q.size()){
    	//cout<<"OK"<<endl;
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=h[u];i!=-1;i=nex[i]){
        
            int v=e[i];
            //cout<<v<<endl;
            if(d[v]>d[u]+w[i]){
                d[v]=d[u]+w[i];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int cnt[N];
bool spfa2(){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    for(int s=1;s<=n;++s){
        dis[s]=inf;
        vis[s]=1;
        q.push(s);
    }
    dis[1]=0;
    while(q.size()){
	 
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=h[u];i!=-1;i=nex[i]){
            int v=e[i];
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    cnt[v]=cnt[u]+1;
                    if(cnt[v]>=n)return true;
                }
            }
        }
    }
    return false;
}
typedef pair<ll,int> pp;
priority_queue<pp,vector<pp>,greater<pp> >pq;
void dijk(int s){
    for(int i=1;i<=n;++i)dis[i]=inf;
    memset(vis,0,sizeof vis);
    dis[s]=0;
    pq.push((pp){0,s});
    while(pq.size()){
	
        int u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i!=-1;i=nex[i]){
            int v=e[i];
            //cout<<u<<" "<<v<<" "<<dis[u]<<" "<<dis[v]<<" "<<w[i]<<endl;
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                pq.push((pp){dis[v],v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    if(spfa2())cout<<-1<<endl;
    else {
    	
        for(int i=1;i<=n;++i){
            add(n+1,i,0);
        }
        spfa(n+1);
        for(int u=1;u<=n;++u){
            for(int i=h[u];i!=-1;i=nex[i]){
                int v=e[i];
                w[i]+=d[u]-d[v];
                //cout<<u<<" "<<v<<" "<<d[u]<<" "<<d[v]<<" "<<w[i]<<endl;
            }
        }
        
        for(int i=1;i<=n;++i){
            ll ans=0;
            dijk(i);
            for(int j=1;j<=n;++j){
                
                if(dis[j]==inf)ans+=(ll)INF*j;
                else ans+=(dis[j]+d[j]-d[i])*j;
                //cout<<i<<" "<<j<<" "<<dis[j]<<" "<<(dis[j]+d[j]-d[i])<<endl;
            }
            cout<<ans<<endl;
            
        }
    }
    
    return 0;
}