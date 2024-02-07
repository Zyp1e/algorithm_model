/*https://www.luogu.com.cn/problem/CF786B*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10,M=N*30,D=N*5;
typedef pair<int,int>pp;
int a[M];
int h[M],e[M],ne[M],w[M],idx;
void add(int a,int b,int c){
    e[++idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
}
void build(int id,int l,int r){
	if(l==r){
		a[l]=id;
	}else {
		int mid=(l+r)>>1;
        add(id,id*2,0);
        add(id,id*2+1,0);
        add(id*2+D,id+D,0);
        add(id*2+1+D,id+D,0);
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
	}
}
void modify(int id,int l,int r,int ql,int qr,int v,int w,int op){
    if(l==ql&&r==qr){
		if(op)add(id+D,v,w);
        else add(v+D,id,w);
		return;
	}
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id*2,l,mid,ql,qr,v,w,op);
	else if(ql>mid)modify(id*2+1,mid+1,r,ql,qr,v,w,op);
	else {
		modify(id*2,l,mid,ql,mid,v,w,op);
		modify(id*2+1,mid+1,r,mid+1,qr,v,w,op);
	}
}
int dis[M],vis[M];
priority_queue<pp,vector<pp>,greater<pp> > q;
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
    int n,qq,s;
    cin>>n>>qq>>s;
    memset(h,-1,sizeof h);
    build(1,1,n);
    for(int i=1;i<=n;++i){
        add(a[i],a[i]+D,0);
        add(a[i]+D,a[i],0);
    }
    for(int i=1;i<=qq;++i){
        int opt;
        cin>>opt;
        if(opt==1){
            int v,u,w;
            cin>>v>>u>>w;
            add(a[v]+D,a[u],w);
        }else {
            int v,l,r,w;
            cin>>v>>l>>r>>w;
            modify(1,1,n,l,r,a[v],w,opt%2);
        }
    }
    dijk(a[s]+D);
    for(int i=1;i<=n;++i){
        if(dis[a[i]]==0x3f3f3f3f3f3f3f3f)cout<<-1<<" ";
        else cout<<dis[a[i]]<<" ";
    }
    cout<<endl;
    
    return 0;
}