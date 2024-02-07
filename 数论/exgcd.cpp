/*https://www.acwing.com/problem/content/879/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		int x,y;
		exgcd(a,b,x,y);
		cout<<x<<" "<<y<<endl;
	}
	
	return 0;
} 