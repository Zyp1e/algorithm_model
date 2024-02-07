/*https://www.luogu.com.cn/problem/P5788*/
#include<bits/stdc++.h>//STL版
#define int long long
using namespace std;
#define endl '\n'
const int N=3e6+10;
int n;
int a[N],f[N];
stack<int>stk;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
	{
		while(!stk.empty()&&a[stk.top()]<=a[i]) stk.pop();
		f[i]=stk.empty()?0:stk.top();
		stk.push(i);
	}
    for(int i=1;i<=n;++i)cout<<f[i]<<" ";
    cout<<endl;
    return 0;
}
/*#include<bits/stdc++.h>//数组版
#define int long long
using namespace std;
#define endl '\n'
const int N=3e6+10;
int n;
int a[N],f[N],hh;
int stk[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--)
	{
		while(hh>0&&a[stk[hh]]<=a[i]) hh--;
		f[i]=hh?stk[hh]:0;
		stk[++hh]=i;
	}
    for(int i=1;i<=n;++i)cout<<f[i]<<" ";
    cout<<endl;
    return 0;
}*/