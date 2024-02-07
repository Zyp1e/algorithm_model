/*https://www.acwing.com/problem/content/863/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n1,n2,m;
const int N=510,M=1e5+10;;
int e[M],ne[M],h[N],idx;
int match[N];
bool vis[N];
void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}
bool find(int u){
    for(int i=h[u];i!=-1;i=ne[i]){
        int v=e[i];
        if(!vis[v]){
            vis[v]=true;
            if(match[v]==0||find(match[v])){
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    memset(h,-1,sizeof h);
	cin>>n1>>n2>>m;
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
	
    int res=0;
    for(int i=1;i<=n1;++i){
        memset(vis,false,sizeof vis);
        if(find(i))++res;
    }
    cout<<res<<endl;
	return 0;
} 