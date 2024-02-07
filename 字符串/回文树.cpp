/*https://www.luogu.com.cn/problem/P5496*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
typedef pair<int,int>pp;
int a[N];
struct PAM  {
    static constexpr int M = 26;
    int n;
    vector<array<int, M>> t;
    vector<int> link, len, s, trans, val, count;
    int cur, cnt;

    PAM(){}
    PAM(int x) {init(x);}

    void init(int x) {
        n = x + 2;
        t.assign(n, {});
        link.assign(n, 0);//fail指针
        count.assign(n, 0);
        val.assign(n, 0);//回文串个数
        len.assign(n, 0);
        s.assign(n, -1);
        trans.assign(n, 0);
        cur = 0;
        cnt = 2;
        len[1] = -1;
        link[0] = link[1] = 1;
    }


    int extend(int p, int c) {
        s[++cur] = c;
        int now = getfail(p);
        if (!t[now][c]) {
            int u = cnt++;
            len[u] = len[now] + 2;
            link[u] = t[getfail(link[now])][c];
            /*if (len[u] < 2)  {
                trans[u] = link[u]; 
            } else {
                int tmp = trans[now];
                while (s[cur - len[tmp] - 1] != s[cur] || ((len[tmp] + 2) << 1) > len[u]) tmp = link[tmp];
                //len[tmp]+2
                trans[u] = t[tmp][c];
                 val[u] = val[link[u]] + 1;

            }
            count[u] = 2 * len[trans[u]] == len[u];
            count[u] += count[link[u]];*/
            val[u] = val[link[u]] + 1;
            t[now][c] = u;
        }
        p = t[now][c];
        //val[p]++;
        return p;
    }

    int getfail(int x) {
        while (s[cur - len[x] - 1] != s[cur]) x = link[x];
        return x;
    }

} pam;
void solve()
{
    string str;
    cin>>str;
    int n=str.size();
    pam.init(n);
    int k=0;
    int p=1;
    for(int i=0;i<n;++i){
        char ch=(str[i]-97+k)%26+97;
        p=pam.extend(p,ch-'a');
        k=pam.val[p];
        cout<<k<<" ";
    }
    cout<<endl;
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