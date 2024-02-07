/*https://www.luogu.com.cn/problem/P8435*/
#include<bits/stdc++.h>//割点为属于至少两个双连通分量的点
#define int long long
using namespace std;
#define endl '\n'
const int N=5e5+10,M=2e6+10;
int n,m;
int e[M*2],nex[M*2],h[N],idx;
vector<vector<int> >res;
vector<int>cut;
stack<int>stk;
int cnt;
void add(int a,int b){
    e[++idx]=b;
    nex[idx]=h[a];
    h[a]=idx;
}
int dfn[N],low[N],tot,deg[N];
void dfs(int u,int f){
    dfn[u]=low[u]=++tot;
    int child=0;
    stk.push(u);
    for(int i=h[u];i!=-1;i=nex[i]){
        int v=e[i];
        if(v==f)continue;
        if(!dfn[v]){
            dfs(v,u);
            ++child;
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]){
                //++deg[u];//割点
                vector<int>temp;
                temp.push_back(u);
                ++cnt;
                while(1){
                    int vv=stk.top();
                    //deg[vv]++;
                    stk.pop();
                    temp.push_back(vv);
                    if(vv==v)break;
                }
                sort(temp.begin(),temp.end());
                res.push_back(temp);
            }

        }else {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(child==0&&f==0){
        vector<int>temp;
        ++cnt;
        temp.push_back(u);
        res.push_back(temp);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=0;i<=n;++i)h[i]=-1;

    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;++i){
        if(!dfn[i])dfs(i,0);
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
    /*for(int i=1;i<=n;++i){
        if(deg[i]>1)cut.push_back(i);
    }
    cout<<cut.size()<<endl;
    for(auto &x:cut){
        cout<<x<<" ";
    }
    cout<<endl;*/
    return 0;
}