/*https://www.luogu.com.cn/problem/P3376*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=5e3+10;
int n,m,s,t;
int e[N*N],w[N*N],nex[N*N],h[N],idx=1;
int pre[N];
int mf[N];//s~v上的流量上限
void add(int a,int b,int c){
    e[++idx]=b;
    w[idx]=c;
    nex[idx]=h[a];
    h[a]=idx;
}
bool bfs(){
    for(int i=0;i<=n;++i)mf[i]=0;
    queue<int>q;
    q.push(s);
    mf[s]=1e9;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=h[u];i!=-1;i=nex[i]){
            int v=e[i];
            if(mf[v]==0&&w[i]){
                mf[v]=min(mf[u],w[i]);
                pre[v]=i;
                q.push(v);
                if(v==t)return true;
            }
        }
    }
    return false;
}
int EK(){
    int flow=0;
    while(bfs()){
        int v=t;
        while(v!=s){
            int i=pre[v];
            w[i]-=mf[t];
            w[i^1]+=mf[t];
            v=e[i^1];
        }
        flow+=mf[t];
    }
    return flow;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>s>>t;
    for(int i=0;i<=n;++i)h[i]=-1;
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c; 
        add(a,b,c);
        add(b,a,0);
    }
    cout<<EK()<<endl;
    return 0;
}