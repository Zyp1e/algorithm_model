/*http://oj.daimayuan.top/course/15/problem/819*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,q;
const int N=3e4+10,inf=1e9;
int w[N];
int e[N*2],nex[N*2],h[N],idx;
int l[N],r[N],idd[N],sz[N],hs[N],tot,top[N],dep[N],fa[N];
void add(int a,int b){
    e[++idx]=b,nex[idx]=h[a],h[a]=idx;
}
struct info{
    int maxv,sum;
};
struct Node{
    info val;
}node[N*4];
info operator+(const info &a,const info &b){
    return {max(a.maxv,b.maxv),a.sum+b.sum};
}
void update(int id){
    node[id].val=node[id*2].val+node[id*2+1].val;
}
void build(int id,int l,int r){
    if(l==r){
        node[id].val={w[idd[l]],w[idd[l]]};
    }else{
        int mid=(l+r)>>1;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        update(id);
    }
}
void change(int id,int l,int r,int pos,int val){
    if(l==r){
        node[id].val={val,val};
    }else {
        int mid=(l+r)>>1;
        if(pos<=mid)change(id*2,l,mid,pos,val);
        else change(id*2+1,mid+1,r,pos,val);
        update(id);
    }
}
info query(int id,int l,int r,int ql,int qr){
    if(l==ql&&r==qr){
        return node[id].val;
    }else {
        int mid=(l+r)>>1;
        if(qr<=mid)return query(id*2,l,mid,ql,qr);
        else if(ql>mid)return query(id*2+1,mid+1,r,ql,qr);
        else {
            return query(id*2,l,mid,ql,mid)+query(id*2+1,mid+1,r,mid+1,qr);
        }
    }
}
//第一遍DFS，子树大小，重儿子，父亲，深度
void dfs1(int u,int f){
    sz[u]=1;
    hs[u]=-1;
    fa[u]=f;
    dep[u]=dep[f]+1;
    for(int i=h[u];i!=-1;i=nex[i]){
        int v=e[i];
        if(v==f)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(hs[u]==-1||sz[v]>sz[hs[u]])hs[u]=v;
    }
}
//第二遍DFS，每个点的DFS序，重链上的链头元素
void dfs2(int u,int t){
    top[u]=t;
    l[u]=++tot;
    idd[tot]=u;
    if(hs[u]!=-1){
        dfs2(hs[u],t);
    }
    for(int i=h[u];i!=-1;i=nex[i]){
        int v=e[i];
        if(v!=fa[u] &&v!=hs[u]){
            dfs2(v,v);
        }
    }
    r[u]=tot;
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])v=fa[top[v]];
		else u=fa[top[u]];
	}
	if(dep[u]<dep[v])return u;
	else return v;
} 
info qry(int u,int v){
    info ans=(info){-inf,0};
    //cout<<"OK "<<u<<" "<<v<<" "<<top[u]<<" "<<top[v]<<" "<<endl;
    while(top[u]!=top[v]){
		//cout<<"OK "<<u<<" "<<v<<" "<<top[u]<<" "<<top[v]<<" "<<fa[top[u]]<<" "<<fa[top[v]]<<" "<<fa[top[u]]<<" "<<dep[top[u]]<<" "<<dep[top[v]]<<endl;
        if(dep[top[u]]<dep[top[v]]){
            ans=ans+query(1,1,n,l[top[v]],l[v]);
            v=fa[top[v]];
        }else {
            ans=ans+query(1,1,n,l[top[u]],l[u]);
            u=fa[top[u]];
        }
        //cout<<"dddddd"<<u<<" "<<v<<" "<<ans.maxv<<" "<<ans.sum<<endl;
    }
    if(dep[u]<=dep[v])ans=ans+query(1,1,n,l[u],l[v]);
    else ans=ans+query(1,1,n,l[v],l[u]);
    //cout<<"+++++"<<ans.maxv<<" "<<ans.sum<<endl;
    return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i)cin>>w[i];
	dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    cin>>q;
    while(q--){
        int u,v;
        string opt;
        cin>>opt>>u>>v;
        if(opt[0]=='C')change(1,1,n,l[u],v);
        else {
            info ans=qry(u,v);
			if(opt[1]=='M')cout<<ans.maxv<<endl;
			else cout<<ans.sum<<endl; 
        }
    }
	return 0;
} 