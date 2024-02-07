#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
typedef pair<int,int>pp;
struct DSU {
    int n;
    vector<int> f, sz;
    DSU(){};
    DSU(int n) : n(n), f(n), sz(n, 1) {
        iota(f.begin(), f.end(), 0);
    }
    void init(int k) {
        n = k;
        f.resize(n);
        sz.assign(n, 1);
        iota(f.begin(), f.end(), 0);
    }
    int get(int x) {
        if(f[x] != x) f[x] = get(f[x]);
        return f[x];
    }
    bool same(int x, int y) {
        return get(x) == get(y);
    }
    int size(int x) {
        return sz[get(x)];
    }
    bool merge(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    bool isRoot(int x) {
        return get(x) == x;
    }
 
};
int a[N];
void solve()
{
    int n;
    cin>>n;
    DSU dsu(n+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)	solve();
    return 0;
}