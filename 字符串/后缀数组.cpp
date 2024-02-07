/*https://www.luogu.com.cn/problem/P3809*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N=2e6+10;
char s[N];
int n,m;//n为后缀个数, m为桶的个数
int idd[N],cnt[N],sa[N],rk[N],oldrk[N],key1[N];
int height[N];
//桶数组rk[i],辅助数组idd[i],计数数组cnt[i]
bool cmp(int x, int y, int w) {
  return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void get_sa(){
    int i,p,w;
    for (i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; --i) sa[cnt[rk[i]]--] = i;

    for (w = 1;; w <<= 1, m = p) {  // m=p 就是优化计数排序值域
        for (p = 0, i = n; i > n - w; --i) idd[++p] = i;
        for (i = 1; i <= n; ++i)
        if (sa[i] > w) idd[++p] = sa[i] - w;

        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; ++i) ++cnt[key1[i] = rk[idd[i]]];
        // 注意这里px[i] != i，因为rk没有更新，是上一轮的排名数组

        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; --i) sa[cnt[key1[i]]--] = idd[i];
        memcpy(oldrk + 1, rk + 1, n * sizeof(int));
        for (p = 0, i = 1; i <= n; ++i)
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        if (p == n) {
            break;
        }
    }
}  
void get_height(){
    int i,j,k;
    for(i=1;i<=n;i++)rk[sa[i]]=i;
    for(i=1,k=0;i<=n;i++){ //枚举后缀i
        if(rk[i]==1)continue;//第一名height为0
        if(k)k--;//上一个后缀的height值减1
        int j=sa[rk[i]-1];//找出后缀i的前邻后缀j
        while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k])k++;
        height[rk[i]]=k;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>s+1;
    n=strlen(s+1); m=127;
    get_sa();
    //get_height();
    for(int i=1;i<=n;i++)cout<<sa[i]<<" "<<rk[i]<<" \n";
    //for(int i=1;i<=n;i++)cout<<height[i]<<" \n"[i==n];
    
    return 0;
}