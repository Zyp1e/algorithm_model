/*https://www.luogu.com.cn/problem/P3381*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=5e3+10;
int n,m,s,t;
int e[N*N],w[N*N],cs[N*N],nex[N*N],h[N],idx=1;
int pre[N],mf[N],d[N],vis[N];
void add(int a,int b,int c,int d){
    e[++idx]=b;
    cs[idx]=c;
    w[idx]=d;
    nex[idx]=h[a];
    h[a]=idx;
}
bool spfa(){
    for(int i=0;i<=n;++i)mf[i]=0,d[i]=0x3f3f3f3f;
    queue<int>q;
    q.push(s);
    d[s]=0;
    mf[s]=1e9;
    vis[s]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=h[u];i!=-1;i=nex[i]){
            int v=e[i];
            if(d[v]>d[u]+w[i]&&cs[i]){
                d[v]=d[u]+w[i];
                mf[v]=min(mf[u],cs[i]);
                pre[v]=i;
                if(!vis[v])q.push(v),vis[v]=1;
            }
        }
    }
    return mf[t]>0;
}
int flow=0,cost=0;
void EK(){
    while(spfa()){
        int v=t;
        while(v!=s){
            int i=pre[v];
            cs[i]-=mf[t];
            cs[i^1]+=mf[t];
            v=e[i^1];
        }
        flow+=mf[t];
        cost+=mf[t]*d[t];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>s>>t;
    for(int i=0;i<=n;++i)h[i]=-1;
    for(int i=1;i<=m;++i){
        int a,b,c,d;
        cin>>a>>b>>c>>d; 
        add(a,b,c,d);
        add(b,a,0,-d);
    }
    EK();
    cout<<flow<<" "<<cost<<endl;
    return 0;
}