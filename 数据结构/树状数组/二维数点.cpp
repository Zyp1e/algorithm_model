/*http://oj.daimayuan.top/course/15/problem/686*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,q;
const int N=2e5+10;
int c[N],a[N],ans[N];
vector<array<int,4> >event;
vector<int>vx; 
void modify(int x,int d){
	for(;x<=n;x+=x&(-x)){
		c[x]+=d;
	}
}
int query(int x){
	int sum=0;
	for(;x;x-=x&(-x)){
		sum+=c[x];
	}
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		event.push_back({y,0,x});
		vx.push_back(x);
	}
	for(int i=1;i<=q;++i){
		int X1,Y1,X2,Y2;
		cin>>X1>>X2>>Y1>>Y2;
		event.push_back({Y2,2,X2,i});
		event.push_back({Y1-1,2,X1-1,i});
		event.push_back({Y1-1,1,X2,i});
		event.push_back({Y2,1,X1-1,i});
	}
	sort(event.begin(),event.end());
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(auto &evt:event){
		if(evt[1]==0){
			int y=lower_bound(vx.begin(),vx.end(),evt[2])-vx.begin()+1;
			modify(y,1);
		}else {
			int y=upper_bound(vx.begin(),vx.end(),evt[2])-vx.begin();
			//int y2=lower_bound(vx.begin(),vx.end(),evt[2])-vx.begin()+1;
			//printf("%d %d %d %d\n",y,y2,evt[2],vx[0]);
			if(evt[1]==1){
				ans[evt[3]]-=query(y);
			}else ans[evt[3]]+=query(y);
		}
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<endl;
	}
	return 0;
} 