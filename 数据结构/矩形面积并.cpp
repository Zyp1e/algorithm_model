/*http://oj.daimayuan.top/course/15/problem/688*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n;
const int N=2e5+10;
vector<array<int,4> >event;
vector<int>vx;

struct info{
	int minv,cnt;
};
struct Node{
	int t;
	info val;
}node[N*8];
info operator+(const info &a,const info &b){
	if(a.minv<b.minv){
		return a;
	}else if(b.minv<a.minv)return b;
	else return{a.minv,a.cnt+b.cnt};
}
void update(int id){
	node[id].val=node[id*2].val+node[id*2+1].val;
}
void settag(int id,int t){
	node[id].val.minv+=t;
	node[id].t+=t;
}
void pushdown(int id){
	if(node[id].t!=0){
		settag(id*2,node[id].t);
		settag(id*2+1,node[id].t);
		node[id].t=0;
	}
}
void build(int id,int l,int r){
	if(l==r){
		node[id].val={0,vx[r]-vx[r-1]};
	} else {
		int mid=(l+r)>>1;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		update(id);
	}
}
void modify(int id,int l,int r,int ql,int qr,int t){
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		int X1,X2,Y1,Y2;
		cin>>X1>>X2>>Y1>>Y2;
		vx.push_back(X1);
		vx.push_back(X2);
		event.push_back({Y1,1,X1,X2});
		event.push_back({Y2,-1,X1,X2});
	}
	sort(event.begin(),event.end());
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	int m=vx.size()-1;
	build(1,1,m);
	int prey=0,sum=0,tot=node[1].val.cnt;
	for(auto &evt:event){
		int cov=tot;
		if(node[1].val.minv==0){
			cov=tot-node[1].val.cnt;
		}
		sum+=cov*(evt[0]-prey);
		prey=evt[0];
		int x1=lower_bound(vx.begin(),vx.end(),evt[2])-vx.begin()+1;
		int x2=lower_bound(vx.begin(),vx.end(),evt[3])-vx.begin();
		if(x1>x2)continue;
		modify(1,1,m,x1,x2,evt[1]);
	}
	cout<<sum<<endl;
	return 0;
} 