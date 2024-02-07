/*http://oj.daimayuan.top/course/15/problem/634*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=2e5+10;
int a[N],c[N]; 
int n,q;
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x + 1; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
using BIT = Fenwick<int>;
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
		cin>>a[i];
		modify(i,a[i]);
	}
	while(q--){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,d;
			cin>>x>>d;
			modify(x,d-a[x]);
			a[x]=d;
		}else {
			int x;
			cin>>x;
			cout<<query(x)<<endl;
		}
	}
	return 0;
} 