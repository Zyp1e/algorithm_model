/*http://oj.daimayuan.top/course/15/problem/719*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,q;
const int N=2e5+10;
int fa[N],w[N];
int find(int x){
	if(x==fa[x])return x;
	int p=fa[x];
	find(p);
	w[x]=w[x]+w[p];
	return fa[x]=fa[p];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	int t=0;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		w[i]=0;
	}
	for(int i=1;i<=q;++i){
		int opt,l,r;
		cin>>opt>>l>>r;
		int ql=(l+t)%n+1,qr=(r+t)%n+1;
		
		if(opt==1){
			int x;
			cin>>x;
			if(find(ql)==find(qr))continue;
			w[fa[ql]]=x-w[ql]+w[qr];
			fa[fa[ql]]=fa[qr]; 
		}else {
			if(find(ql)!=find(qr))continue;
			cout<<w[ql]-w[qr]<<endl;
			t=abs(w[ql]-w[qr]);
		}
	}
	
	return 0;
} 