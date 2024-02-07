/*https://www.acwing.com/problem/content/description/850/*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e5+10;
int n,m;
int e[N],h[N],ne[N],cnt;
int ind[N];
void add(int a,int b)
{
    e[cnt]=b,ne[cnt]=h[a],h[a]=cnt++;
}
queue<int>q,ans;
void topu()
{
    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        ans.push(tmp);
        for(int i=h[tmp];i!=-1;i=ne[i])
        {
            int j=e[i];
            ind[j]--;
            if(ind[j]==0)
                q.push(j);
        }
    }

    if(ans.size()!=n)
    {
        cout<<-1<<endl;   
    }
    else
    {
        while(!ans.empty())
        {
            cout<<ans.front()<<" ";
            ans.pop();
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(h,-1,sizeof(h));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        ind[y]++;
    }
    for(int i=1;i<=n;i++)
        if(ind[i]==0)
            q.push(i);
    topu();
    
    return 0;
}