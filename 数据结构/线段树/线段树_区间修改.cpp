/*http://oj.daimayuan.top/course/15/problem/660*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,q;
const int N=2e5+10,mod=1e9+7;
int a[N];
struct info{
	int sum;
};
struct tag{
	int mul,add;
};
struct Node{
	info val;
    int sz;
	tag t;
}node[N*4];
info operator+(const info &a,const info &b){
	return {(a.sum+b.sum)%mod};
}
tag operator+(const tag &a,const tag &b){
	return {a.mul*b.mul%mod,(a.add*b.mul+b.add)%mod};	
}
void settag(int id,tag t){
	node[id].t=node[id].t+t;
	node[id].val.sum=(node[id].val.sum*t.mul+node[id].sz*t.add)%mod;
}
void update(int id){
	node[id].val=node[id*2].val+node[id*2+1].val;
}
void pushdown(int id){
	if(node[id].t.mul!=1||node[id].t.add!=0){
		settag(id*2,node[id].t);
		settag(id*2+1,node[id].t);
		node[id].t={1,0};
	}
}
void build(int id,int l,int r){
	node[id].sz=r-l+1;
	node[id].t={1,0};
	if(l==r)node[id].val.sum=a[l];
	else {
		int mid=(l+r)>>1;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		update(id);
	}
}
void modify(int id,int l,int r,int ql,int qr,tag t){
	if(l==ql&&r==qr){
		settag(id,t);
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id*2,l,mid,ql,qr,t);
	else if(ql>mid)modify(id*2+1,mid+1,r,ql,qr,t);
	else {
		modify(id*2,l,mid,ql,mid,t);
		modify(id*2+1,mid+1,r,mid+1,qr,t);
	}
	update(id);
}
info query(int id,int l,int r,int ql,int qr){
	if(ql==l&&qr==r){
		return node[id].val;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id*2,l,mid,ql,qr);
	else if(ql>mid)return query(id*2+1,mid+1,r,ql,qr);
	else {
		return query(id*2,l,mid,ql,mid)+query(id*2+1,mid+1,r,mid+1,qr);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	build(1,1,n);
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int l,r,d;
			cin>>l>>r>>d;
			modify(1,1,n,l,r,tag{1,d});
		}else if(opt==2){
			int l,r,d;
			cin>>l>>r>>d;
			modify(1,1,n,l,r,tag{d,0}); 
		}else if(opt==3){
			int l,r,d;
			cin>>l>>r>>d;
			modify(1,1,n,l,r,tag{0,d});
		}else {
			int l,r;
			cin>>l>>r;
			auto res=query(1,1,n,l,r);
			cout<<res.sum<<endl;
		}
	}
	
	return 0;
} 