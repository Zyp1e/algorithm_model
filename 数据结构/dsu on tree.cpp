/*http://oj.daimayuan.top/course/15/problem/817*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
int n;
const int N=1e5+10;
int l[N],r[N],idd[N],sz[N],hs[N],tot;
int c[N],cnt[N];//每个颜色出现次数
int maxcnt;//众数出现次数
int sumcnt;
int ans[N];
vector<int>e[N];
void add(int x){
    x=c[x];
    cnt[x]++;
    if(cnt[x]>maxcnt)maxcnt=cnt[x],sumcnt=0;
    if(cnt[x]==maxcnt)sumcnt+=x;
}
void del(int x){
    x=c[x];
    cnt[x]--;
}
void dfs1(int u,int f){
    l[u]=++tot;
    idd[tot]=u;
    sz[u]=1;
    hs[u]=-1;
    for(auto &v:e[u]){
        if(v==f)continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(hs[u]==-1||sz[v]>sz[hs[u]])
			hs[u]=v;
    }
    r[u]=tot;
}
void dfs2(int u,int f,bool keep){
    for(auto &v:e[u]){
        if(v!=f&&v!=hs[u]){
            dfs2(v,u,0);
        }
    }
    if(hs[u]!=-1){
        dfs2(hs[u],u,1);
    }
    for(auto &v:e[u]){
        if(v!=f &&v!=hs[u]){
            for(int x=l[v];x<=r[v];++x){
                add(idd[x]);
            }
        }
    }
    add(u);
    ans[u]=sumcnt;
    if(!keep){
        sumcnt=0;
        maxcnt=0;
        for(int x=l[u];x<=r[u];++x){
            del(idd[x]);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
    return 0;
}