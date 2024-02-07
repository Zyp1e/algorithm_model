/*https://www.luogu.com.cn/problem/P6136*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10,M=1e6+10,INF=1e18;
int a[N];
int root,idx;
struct Node{
    int s[2];
    int p,v;//p父节点，v值
    int size,cnt;
    void init(int _v,int _p){
        v=_v,p=_p;
        size=cnt=1;
    }
}node[N+M];
void update(int u){
    node[u].size=node[node[u].s[0]].size+node[node[u].s[1]].size+node[u].cnt;
}
void rotate(int x){
    int y=node[x].p,z=node[y].p;
    int ky=node[y].s[1]==x,kz=node[z].s[1]==y;
    node[z].s[kz]=x,node[x].p=z;
    node[y].s[ky]=node[x].s[ky^1],node[node[x].s[ky^1]].p=y;
    node[x].s[ky^1]=y,node[y].p=x;
    update(y),update(x);
}
void splay(int x,int k){
    while(node[x].p!=k){
        int y=node[x].p,z=node[y].p;
        if(z!=k){
            if((node[y].s[1]==x)^(node[z].s[1]==y))rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k)root=x;
}
void find(int v){
    int x=root;
    
    while(node[x].s[v>node[x].v]&&v!=node[x].v)
        x=node[x].s[v>node[x].v];
    splay(x,0);
}
void insert(int v){
    int u=root,p=0;
    while(u&&node[u].v!=v){
        p=u;
        u=node[u].s[v>node[u].v];
    }
    if(u)node[u].cnt++;
    else {
        u=++idx;
        node[p].s[v>node[p].v]=u;
        node[u].init(v,p);
    }
    splay(u,0);
}
int prev(int v){
    find(v);
    int u=root;
    if(node[u].v<v)return u;
    u=node[u].s[0];
    while(node[u].s[1]){
        u=node[u].s[1];
    }
    splay(u,0);
    return u;
}
int nex(int v){
    find(v);
    int u=root;
    if(node[u].v>v)return u;
    u=node[u].s[1];
    while(node[u].s[0]){
        u=node[u].s[0];
    }
    splay(u,0);
    return u;
}
void del(int x){
    int pre=prev(x),ne=nex(x);
    splay(pre,0),splay(ne,pre);
    int d=node[ne].s[0];
    if(node[d].cnt>1)
        node[d].cnt--,splay(d,0);
    else node[ne].s[0]=0,splay(ne,0);
}
int rkx(int u){
    insert(u);
    int res=node[node[root].s[0]].size;
    del(u);
    return res;
}
int getk(int k){
    int u=root;
    while(1){
        int y=node[u].s[0];
        if(node[y].size+node[u].cnt>=k){
            if(node[y].size>=k)u=node[u].s[0];
            else break;
        }
        else {
            k-=node[y].size+node[u].cnt;
            u=node[u].s[1];
        }
    }
    splay(u,0);
    return node[u].v;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    insert(INF),insert(-INF);
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        insert(x);
    }
    int res=0,las=0;
    for(int i=1;i<=m;++i){
        int op,x;
        cin>>op>>x;
        x^=las;
        //cout<<"op"<<op<<" "<<x<<endl;
        if(op==1){
            insert(x);
        }else if(op==2){
            del(x);
        }else if(op==3){
            las=rkx(x);
        }else if(op==4){
            las=getk(x+1);
        }else if(op==5){
            las=node[prev(x)].v;
        }else las=node[nex(x)].v;
        //cout<<las<<endl;
        if(op==3||op==4||op==5||op==6)res^=las;
    }
    cout<<res<<endl;
    
    return 0;
}