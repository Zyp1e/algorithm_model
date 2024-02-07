#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
int w[N];
int n,m;
int h[N],e[N*4],ne[N*4],idx;
int sz[N],hs[N],fa[N],dep[N];
int l[N],r[N],top[N],idd[N],tot;
void add(int a,int b){
    e[++idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
}
struct info{
    int sum;
};
struct Node{
    info val;
    int size;
    int tag;
}node[N*4];
info operator+(const info &a,const info &b){
    return {a.sum+b.sum};
}
void settag(int id,int t){
    node[id].tag+=t;
    //cout<<id<<" "<<node[id].val.sum<<" "<<node[id].val.size<<endl;
    node[id].val.sum+=node[id].size*t;
    
}
void update(int id){
    node[id].val=node[id<<1].val+node[id<<1|1].val;
}
void pushdown(int id){
    if(node[id].tag){
        int t=node[id].tag;
        settag(id<<1,t);
        settag(id<<1|1,t);
        node[id].tag=0;
    }
}
void build(int id,int l,int r){
    node[id].size=r-l+1;
    if(l==r){
        node[id].val={w[idd[l]]};

    }else {
        int mid=l+r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
        update(id);
    }
}
void modify(int id,int l,int r,int ql,int qr,int t){
    if(l==ql&&r==qr){
    	settag(id,t);
		return;	
	}
    //cout<<id<<" "<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
    pushdown(id);
    int mid=l+r>>1;
    if(qr<=mid)modify(id<<1,l,mid,ql,qr,t);
    else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,t);
    else {
        modify(id<<1,l,mid,ql,mid,t);
        modify(id<<1|1,mid+1,r,mid+1,qr,t);
    }
    update(id);
}
int query(int id,int l,int r,int ql,int qr){
    if(l==ql&&r==qr)return node[id].val.sum;
    else {
        pushdown(id);
        int mid=l+r>>1;
        if(qr<=mid)return query(id<<1,l,mid,ql,qr);
        else if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
        else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
    }
}
void dfs1(int u,int f){
    sz[u]=1;
    hs[u]=-1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=h[u];i!=-1;i=ne[i]){
        int v=e[i];
        if(v==f)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(hs[u]==-1||sz[v]>sz[hs[u]])hs[u]=v;
    }
}
void dfs2(int u,int t){
    top[u]=t;
    l[u]=++tot;
    //cout<<"u:"<<u<<" "<<l[u]<<endl;
    idd[tot]=u;
    if(hs[u]!=-1)dfs2(hs[u],t);
    for(int i=h[u];i!=-1;i=ne[i]){
        int v=e[i];
        if(v!=fa[u]&&v!=hs[u]){
            dfs2(v,v);
        }
    }
    r[u]=tot;
}
void mfy(int u,int v,int k){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]])swap(u,v);
            //cout<<"mfy:"<<u<<" "<<top[u]<<" "<<v<<" "<<top[v]<<" "<<fa[top[v]]<<" "<<l[v]<<endl;
			modify(1,1,n,l[top[v]],l[v],k);
            //cout<<query(1,1,n,l[top[v]],l[v])<<endl;
            v=fa[top[v]];
            
    }
    if(dep[u]>dep[v])swap(u,v);
    modify(1,1,n,l[u],l[v],k);
}
int qry(int u,int v){
    int ans=0;    
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]])swap(u,v);
        //cout<<"qfy:"<<u<<" "<<top[u]<<" "<<v<<" "<<top[v]<<" "<<fa[top[v]]<<endl;
        ans+=query(1,1,n,l[top[v]],l[v]);
        v=fa[top[v]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans+=query(1,1,n,l[u],l[v]);
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=0;i<=n+1;++i)h[i]=-1;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    dfs2(1,0);
    build(1,1,n);
    cin>>m;
    while(m--){
        int op,u,v,k;
        cin>>op;
		//cout<<"op:"<<op<<endl;
        if(op==1){
            cin>>u>>v>>k;
            mfy(u,v,k);
        }else if(op==2){
            cin>>u>>k;
            modify(1,1,n,l[u],r[u],k);
        }else if(op==3){
            cin>>u>>v;
            cout<<qry(u,v)<<endl;
        }else {
            cin>>u;
            cout<<query(1,1,n,l[u],r[u])<<endl;
        }
        
    }
    
    return 0;
}