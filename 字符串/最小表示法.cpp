/*https://www.luogu.com.cn/problem/P1368*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=3e5+10;
typedef pair<int,int>pp;
int sec[N];
int n;
void solve()
{   
    cin>>n;
    for(int m=0;m<n;++m)cin>>sec[m];
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (sec[(i + k) % n] == sec[(j + k) % n]) {
            k++;
        } else {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    i = min(i, j);
    for(int m=0;m<n;++m){
        cout<<sec[(i+m)%n]<<" \n"[m==n-1];
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--)	solve();
    return 0;
}