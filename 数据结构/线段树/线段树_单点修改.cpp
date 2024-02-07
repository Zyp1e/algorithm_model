/*http://oj.daimayuan.top/course/15/problem/658*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,q;
const int N=2e5+10;
int a[N];
struct info{
	int ans,s,ps,bs;
}; 
struct Node{
	info val;
}node[N*4];
info operator +(const info &a,const info &b){
	info res;
	res.ans=max({a.ans,b.ans,a.bs+b.ps});
	res.ps=max(a.ps,a.s+b.ps);
	res.bs=max(b.bs,a.bs+b.s);
	res.s=a.s+b.s;
	return res;
}
void update(int id){
	node[id].val=node[id*2].val+node[id*2+1].val;
}
void build(int id,int l,int r){
	if(l==r){
		node[id]={a[l],a[l],a[l],a[l]};
	}else {
		int mid=(l+r)>>1;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		update(id);
	}
}
void change(int id,int l,int r,int pos,int d){
	if(l==r){
		node[id].val={d,d,d,d};
	}else {
		int mid=(l+r)>>1;
		if(pos<=mid)change(id*2,l,mid,pos,d);
		else change(id*2+1,mid+1,r,pos,d);
		update(id);
	}
}
info query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		return node[id].val;
	}
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id*2,l,mid,ql,qr);
	else if(ql>mid)return query(id*2+1,mid+1,r,ql,qr);
	else return query(id*2,l,mid,ql,mid)+query(id*2+1,mid+1,r,mid+1,qr);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	build(1,1,n);
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,d;
			cin>>x>>d;
			change(1,1,n,x,d);
		}else {
			int l,r;
			cin>>l>>r;
			auto res=query(1,1,n,l,r);
			cout<<res.ans<<endl;
		}
	}
	
	return 0;
} 