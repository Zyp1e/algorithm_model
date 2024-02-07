/*https://www.acwing.com/problem/content/description/2490/*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5e4+10,INF=1e9;
int a[N];
int n,m;
struct Node{
    multiset<int>s;
}node[N*4];
void build(int id,int l,int r){
    node[id].s.insert(INF),node[id].s.insert(-INF);
    for(int i=l;i<=r;++i)node[id].s.insert(a[i]);
    if(l==r)return;
    else {
        int mid=l+r>>1;
        build(id<<1,l,mid);
        build(id<<1|1,mid+1,r);
    }
}
void change(int id,int l,int r,int pos,int d){
    node[id].s.erase(node[id].s.find(a[pos]));
    node[id].s.insert(d);
    if(l==r)return;
    else {
        int mid=l+r>>1;
        if(pos<=mid)change(id<<1,l,mid,pos,d);
        else change(id<<1|1,mid+1,r,pos,d);
        
    }
}
int query(int id,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        auto it=node[id].s.lower_bound(x);
        --it;
        return *it;
    }
    int mid=l+r>>1;
    int res=-INF;
    if(qr<=mid)return query(id<<1,l,mid,ql,qr,x);
    else if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr,x);
    else return max(query(id<<1,l,mid,ql,mid,x),query(id<<1|1,mid+1,r,mid+1,qr,x));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(1,1,n);
    while(m--){
        int op,aa,b,x;
        cin>>op;
        if(op==1){
            cin>>aa>>x;
            change(1,1,n,aa,x);
            a[aa]=x;
        }else {
            cin>>aa>>b>>x;
            cout<<query(1,1,n,aa,b,x)<<endl;
        }
    }

    return 0;
}