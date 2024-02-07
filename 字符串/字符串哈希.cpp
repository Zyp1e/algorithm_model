/*https://www.acwing.com/problem/content/843/*/
/*https://www.acwing.com/problem/content/843/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int p=131,N=1e5+10;
int n,m;
char str[N];
int pp[N],h[N];
void init()
{
    for(int i=1;i<=n;++i){
        pp[i]=pp[i-1]*p;
        h[i]=h[i-1]*p+str[i];
        //cout<<i<<" "<<h[i]<<endl;
    }
}
int query(int l,int r){
	//cout<<l<<" "<<r<<" "<< " "<<h[l-1]*pp[r-l+1]<<" "<<h[r]-h[l-1]*pp[r-l+1]<<endl;
    return h[r]-h[l-1]*pp[r-l+1];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
    cin>>str+1;
    pp[0]=1;
    init();
    for(int i=1;i<=m;++i){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(query(l1,r1)==query(l2,r2))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
	
	return 0;
} 