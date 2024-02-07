/*https://www.acwing.com/problem/content/1174/*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
int n,cnt=0;
const int N=4e4+10;
int head[N],to[N],nex[N],dep[N],fa[N][16];
void add(int a,int b){
    to[cnt]=b;
    nex[cnt]=head[a];
    head[a]=cnt++;
}
queue<int>q;
void bfs(int rt){
    memset(dep,0x3f,sizeof dep);
    dep[0]=0,dep[rt]=1;
    q.push(rt);
    while(q.size()){
        int temp=q.front();
        q.pop();
        for(int i=head[temp];i!=-1;i=nex[i]){
            int j=to[i];
            if(dep[j]>dep[temp]+1){
                dep[j]=dep[temp]+1;
                q.push(j);
                fa[j][0]=temp;
                for(int k=1;k<=15;++k){
                    fa[j][k]=fa[fa[j][k-1]][k-1];
                }
            }
        }
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])swap(a,b);
    for(int k=15;k>=0;--k){
        if(dep[fa[a][k]]>=dep[b]){
            a=fa[a][k];
        }
    }
    if(a==b)return a;
    for(int k=15;k>=0;--k){
        if(fa[a][k]!=fa[b][k]){
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(head,-1,sizeof head);
	int rt=0;
	for(int i=1;i<=n;++i){
	    int a,b;
	    cin>>a>>b;
	    if(b==-1)rt=a;
	    else {
	        add(a,b);
	        add(b,a);
	    }
	    
	}
	bfs(rt);
	
	int m;
	cin>>m;
	while(m--){
	    int a,b;
	    cin>>a>>b;
	    int p=lca(a,b);
	    if(p==a)cout<<1<<endl;
	    else if(p==b)cout<<2<<endl;
	    else cout<<3<<endl;
	}
	
	return 0;
} 