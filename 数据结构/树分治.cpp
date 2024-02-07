/*https://www.acwing.com/problem/content/254/*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 10010, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
bool vis[N];
int p[N], q[N];

void add(int a, int b, int c)
{
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}

int dfs1(int u, int fa)  // 求子树大小
{
    if (vis[u]) return 0;
    int res = 1;
    for (int i = h[u]; i!=-1; i = ne[i])
        if (e[i] != fa)
            res += dfs1(e[i], u);
    return res;
}

int dfs2(int u, int fa, int tot, int& wc)  // 求重心
{
    if (vis[u]) return 0;
    int sum = 1, ms = 0;
    for (int i = h[u]; i!=-1; i = ne[i])
    {
        int v = e[i];
        if (v == fa) continue;
        int t = dfs2(v, u, tot, wc);
        ms = max(ms, t);
        sum += t;
    }
    ms = max(ms, tot - sum);
    if (ms <= tot / 2) wc = u;
    return sum;
}

void dfs3(int u, int fa, int dist, int& qt)//求距离
{
    if (vis[u]) return;
    q[qt ++ ] = dist;
    for (int i = h[u]; ~i; i = ne[i])
        if (e[i] != fa)
            dfs3(e[i], u, dist + w[i], qt);
}

int get(int a[], int k)
{
    sort(a, a + k);
    int res = 0;
    for (int i = k - 1, j = -1; i >= 0; i -- )
    {
        while (j + 1 < i && a[j + 1] + a[i] <= m) j ++ ;
        j = min(j, i - 1);
        res += j + 1;
    }
    return res;
}

int calc(int u)
{
    if (vis[u]) return 0;
    int res = 0;
    dfs2(u, -1, dfs1(u, -1), u);
    vis[u] = true;  // 删除重心

    int pt = 0;
    for (int i = h[u]; i!=-1; i = ne[i])
    {
        int v = e[i], qt = 0;
        dfs3(v, -1, w[i], qt);
        res -= get(q, qt);
        for (int k = 0; k < qt; k ++ )
        {
            if (q[k] <= m) res ++ ;
            p[pt ++ ] = q[k];
        }
    }
    res += get(p, pt);

    for (int i = h[u]; i!=-1; i = ne[i]) res += calc(e[i]);
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin>>n>>m && (n || m))
    {
        memset(vis, 0, sizeof vis);
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 1; i < n; i ++ )
        {
            int a, b, c;
            cin>>a>>b>>c;
            add(a, b, c), add(b, a, c);
        }
        cout<<calc(0)<<endl;
    }

    return 0;
}
