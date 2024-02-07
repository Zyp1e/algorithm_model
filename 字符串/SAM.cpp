/*https://www.luogu.com.cn/problem/P3804*/
#include<bits/stdc++.h>
// #define int long long
using namespace std;
#define endl '\n'
typedef long long ll;
const int NN=2e6+10;
typedef pair<int,int>pp;
struct SAM {
    static const int M = 26, N = 1e6;
    struct Node {
        int len;
        int link;
        int sz;
        array<int, M> nxt;
        Node() = default;
    } t[2 * N];
    int cnt;
    SAM() {init();}
    int newNode() {
        int u = cnt++;
        t[u].len = t[u].link = 0;
        t[u].nxt.fill(0);
        t[u].sz=0;
        // t[u].sz=1;
        return u;
    }
    void init() {
        cnt = 0;
        newNode();
        newNode();
        t[0].nxt.fill(1);
        t[0].len = -1;
    }
    int extend(int p, int c) {
        // cerr<<p<<" "<<t[p].nxt[c]<<" "<<t[p].len<<" "<<t[p].link<<endl;
        if (t[p].nxt[c]) {
            int q = t[p].nxt[c];
            if (t[q].len == t[p].len + 1)
                return q;
            int r = newNode();
            t[r] = t[q];
            t[r].sz=0;
            t[r].len = t[p].len + 1;
            t[q].link = r;
            while (t[p].nxt[c] == q) {
                t[p].nxt[c] = r;
                p = t[p].link;
            }
            return r;
        }
        int cur = newNode();
        // cerr<<"cur:"<<cur<<" "<<cnt<<endl;
        t[cur].len = t[p].len + 1;
        t[cur].sz=1;

        while (!t[p].nxt[c]) {
            t[p].nxt[c] = cur;
            p = t[p].link;
        }
        t[cur].link = extend(p, c);
        // cerr<<"cur"<<cur<<" "<<t[cur].link<<" "<<t[cur].len<<endl;
        return cur;
    }
 
    int extend(int p, char c, char offset = 'a') {
        return extend(p, c - offset);
    }
    int nxt(int p, int x) {
        return t[p].nxt[x];
    }
    int nxt(int p, char c, char offset = 'a') {
        return nxt(p, c - 'a');
    }
    int link(int p) {
        return t[p].link;
    }
    int len(int p) {
        return t[p].len;
    }
    int size() {
        return cnt;
    }
} sam;
int h[NN],e[NN],nt[NN],idx;
void add(int a,int b){
    e[++idx]=b;
    nt[idx]=h[a];
    h[a]=idx;
}
ll res=0;
void dfs(int u){
    for(int i=h[u];i!=-1;i=nt[i]){
        dfs(e[i]);
        sam.t[u].sz+=sam.t[e[i]].sz;
    }
    if(sam.t[u].sz!=1){
        // cerr<<sam.t[u].sz<<" "<<sam.t[u].len<<endl;
        res=max(res,1ll*sam.t[u].sz*sam.t[u].len);
        // cerr<<res<<endl;
    }
}
void solve()
{
    memset(h,-1,sizeof h);
    string str;
    cin>>str;
    int n=str.size();
    vector<int>p(n+1);
    p[0]=1;
    for(int i=0;i<n;++i){
        // cerr<<str[i]<<endl;
        p[i+1]=sam.extend(p[i],str[i]);
        // cerr<<p[i+1]<<" "<<sam.t[p[i+1]].nxt[str[i]]<<" "<<sam.t[p[i+1]].len<<" "<<sam.t[p[i+1]].link<<endl;
        // cerr<<"cnt"<<sam.cnt<<endl;
    }

    for(int i=2;i<sam.size();++i){
        add(sam.link(i),i);
    }
    dfs(1);
    cout<<res<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--)	solve();
    return 0;
}