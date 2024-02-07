/*https://www.luogu.com.cn/problem/P4556*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=1e5+10;
typedef pair<int,int>pp;
int a[N];
int e[N*2],h[N],ne[N*2],idx;
int fa[N][20],dep[N];
int root[N];
int ans[N];
int tot;
struct info{
    int sum,res;
};
struct Node{
    int l,r;
    info val;
}node[N*50];
info operator+(const info &a,const info &b){
    if(a.sum<b.sum)return {b.sum,b.res};
    else return{a.sum,a.res};
}
void add(int a,int b){
    e[++idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
}
queue<int>q;
void bfs(int rt){
    memset(dep,0x3f,sizeof dep);
    dep[0]=0,dep[rt]=1;
    q.push(rt);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=h[u];~i;i=ne[i]){
            int j=e[i];
            if(dep[j]>dep[u]+1){
                dep[j]=dep[u]+1;
                q.push(j);
                fa[j][0]=u;
                for(int k=1;k<=17;++k){
                    fa[j][k]=fa[fa[j][k-1]][k-1];
                }
            }
        }
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int k=17;k>=0;--k){
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    }
    if(a==b)return a;
    for(int k=17;k>=0;--k){
        if(fa[a][k]!=fa[b][k]){
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
void update(int id){
    node[id].val=node[node[id].l].val+node[node[id].r].val;
}
int insert(int id,int l,int r,int pos,int val){
    if(!id)id=++tot;
    if(l==r){
        node[id].val.sum+=val;
        node[id].val.res=pos;
        return id;
    }
    int mid=l+r>>1;
    if(pos<=mid)node[id].l=insert(node[id].l,l,mid,pos,val);
    else node[id].r=insert(node[id].r,mid+1,r,pos,val);
    update(id);
    return id;
}
int merge(int p, int q, int l, int r) {
    if (!p) return q;
    if (!q) return p;
    if (l == r) {
        node[p].val.sum += node[q].val.sum;
        return p;
    }
    int mid = (l + r) >> 1;
    node[p].l = merge(node[p].l, node[q].l, l, mid);
    node[p].r = merge(node[p].r, node[q].r, mid + 1, r);
    update(p);
    return p;
}
void cal(int u){
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa[u][0])continue;
        cal(v);
        root[u]=merge(root[u],root[v],1,N);
    }
    ans[u]=node[root[u]].val.res;
    if(node[root[u]].val.sum==0)ans[u]=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    bfs(1);
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        root[a]=insert(root[a],1,N,c,1);
        root[b]=insert(root[b],1,N,c,1);
        int t=lca(a,b);
        root[t]=insert(root[t],1,N,c,-1);
        root[fa[t][0]]=insert(root[fa[t][0]],1,N,c,-1);
    }
    cal(1);
    for(int i=1;i<=n;++i)cout<<ans[i]<<endl;

    return 0;
}