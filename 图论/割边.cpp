/*https://www.luogu.com.cn/problem/P8436*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=5e5+10,M=2e6+10;
int n,m;
vector<pair<int,int> >e[N];
vector<vector<int> >res;
int cnt;
stack<int>stk;
vector<pair<int,int> >bridge;
int dfn[N],low[N],tot;
void dfs(int u,int idd){
    dfn[u]=low[u]=++tot;
    stk.push(u);
    for(auto &temp:e[u]){
        int v=temp.first,id=temp.second;
        if(id!=idd){//非反向边
            if(!dfn[v]){
                dfs(v,id);
                low[u]=min(low[u],low[v]);
                //if(low[v]>dfn[u])bridge.push_back({u,v});//求割边
            }else if(idd!=id){
                low[u]=min(low[u],dfn[v]);
            }
        }
        
        
    }
    if(dfn[u]==low[u]){//求边连通分量
            vector<int>t1;
            ++cnt;
            while(1){
                int vv=stk.top();
                stk.pop();
                t1.push_back(vv);
                if(u==vv)break;
            }
            sort(t1.begin(),t1.end());
            res.push_back(t1);
        }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        e[a].push_back({b,i});
        e[b].push_back({a,i});
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i])dfs(i,-1);
    }
    cout<<cnt<<endl;
    sort(res.begin(),res.end());
    for(auto &x:res){
        cout<<x.size()<<" ";
        for(auto &y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}