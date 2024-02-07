/*https://www.acwing.com/problem/content/description/833/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;

class KMP
{
	vector<int> nx;
	string b;
public:
	KMP(string b)
	{
		this->b = b;
		int n = b.length();
		int j = 0;
		nx.resize(n);
		for (int i = 1; i < n; i++)
		{

			while (j > 0 && b[i] != b[j])
				j = nx[j - 1];
			if (b[i] == b[j])
				j++;
			nx[i] = j;
		}
	}
	int find(string a) // a中出现多少次b
	{
		int n = b.length(), m = a.length();
		int j = 0;
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			while (j > 0 && a[i] != b[j])
				j = nx[j - 1];
			if (a[i] == b[j])
				j++;
			if (j == n)
			{
				ans++;
				j = nx[j - 1];
			}
		}
		return ans;
	}
};
int m,n;
const int N=1e5+10,M=1e6+10;
int nex[N];
char p[N],s[M];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>p+1>>m>>s+1;//若无输入字符串长度先提前存储长度，否则Strlen函数将花费大量时间
	
	for(int i=2,j=0;i<=n;++i){
		while(j&&p[j+1]!=p[i])j=nex[j];
		if(p[j+1]==p[i])++j;
		nex[i]=j;
	}
	for(int i=1,j=0;i<=m;++i){
		while(j&&p[j+1]!=s[i])j=nex[j];
		if(p[j+1]==s[i])++j;
		if(j==n){
            //匹配成功
			cout<<i-n<<" ";
			j=nex[j];
		}
	}
	cout<<endl;
	return 0;
} 
/*3
aba
5
ababa*/