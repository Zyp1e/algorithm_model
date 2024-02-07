/*http://oj.daimayuan.top/course/15/problem/653*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n;
const int N=1e5+10;
int a[N],c[N];
void modify(int x,int d){
	for(;x<=n;x+=(-x)&x){
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
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]=n-a[i]+1;
		
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		sum+=query(a[i]);
		modify(a[i],1);
	}
	cout<<sum<<endl;
	return 0;
} 