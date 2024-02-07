/*https://www.acwing.com/problem/content/description/877/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int qmi(int a,int b,int p){
    int res=1;
	a%=p;
    while(b){
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int a,b,p;
		cin>>a>>b>>p;
		cout<<qmi(a,b,p)<<endl;
	}
	
	return 0;
} 