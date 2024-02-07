/*https://www.acwing.com/problem/content/257/*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int>num;

int n,m,idx;
const int N=1e5+10,M=1e4+10;
int a[N],root[N];
struct info{
    int cnt;
};
struct Node{
    int l,r;
    info val;
}node[N*4+17*N];
info operator+(const info &a,const info &b){
    return {a.cnt+b.cnt};
}
int find(int x){
    return lower_bound(num.begin(),num.end(),x)-num.begin();
}
int build(int l,int r){
    int p=++idx;
    if(l==r)return r;
    int mid=(l+r)>>1;
    node[p].l=build(l,mid);
    node[p].r=build(mid+1,r);
    return p;
}
void update(int p){
    node[p].val=node[node[p].l].val+node[node[p].r].val;
}
int insert(int p,int l,int r,int x){
    int q=++idx;
    node[q]=node[p];
    if(l==r){
        node[q].val.cnt++;
        return q;
    }
    int mid=(l+r)>>1;
    if(x<=mid)node[q].l=insert(node[q].l,l,mid,x);
    else node[q].r=insert(node[q].r,mid+1,r,x);
    update(q);
    return q;
}
int query(int q,int p,int l,int r,int k){
    if(l==r)return r;
    int cnt=node[node[q].l].val.cnt-node[node[p].l].val.cnt;
    int mid=(l+r)>>1;
    if(k<=cnt)return query(node[q].l,node[p].l,l,mid,k);
    else return query(node[q].r,node[p].r,mid+1,r,k-cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    root[0]=build(0,num.size()-1);
    for(int i=1;i<=n;++i){
        root[i]=insert(root[i-1],0,num.size()-1,find(a[i]));
    }
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<num[query(root[r],root[l-1],0,num.size()-1,k)]<<endl;
    }

    return 0;
}