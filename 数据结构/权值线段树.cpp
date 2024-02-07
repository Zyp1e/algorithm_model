/*http://oj.daimayuan.top/course/15/problem/52*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,m,root,tot;
const int N=2e5+10,M=30;
struct Node{
	int s[2];
	int sz;
}node[N*32];
void insert(int x){
	int p=root;
	for(int j=M-1;j>=0;--j){
		node[p].sz+=1;
		int w=(x>>j)&1;
		if(!node[p].s[w])node[p].s[w]=++tot;
		p=node[p].s[w];
	}
	node[p].sz+=1;
}
int query(int x,int k){
	int p=root;
	int ans=0;
	for(int j=M-1;j>=0;--j){
		int w=(x>>j)&1;
		if(node[node[p].s[w]].sz>=k){
			p=node[p].s[w];
		}else {
			k-=node[node[p].s[w]].sz;
			ans^=1<<j;
			p=node[p].s[1^w];  
		}
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	root=++tot;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		insert(x);
	}
	for(int i=1;i<=m;++i){
		int x,k;
		cin>>x>>k;
		cout<<query(x,k)<<endl;
	}
	
	return 0;
} 