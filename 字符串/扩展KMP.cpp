/*https://www.luogu.com.cn/problem/P5410*/
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e7+5;
string t,s;
int z[N],p[N];

void get_z(string s,int n){
    z[1]=n;
    for(int i=2,l,r=0;i<=n;i++){
        if(i<=r)z[i]=min(z[i-l+1],r-i+1);
        while(s[1+z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
}
void get_p(string s,int n,string t,int m){
    for(int i=1,l,r=0;i<=m;i++){
        if(i<=r)p[i]=min(z[i-l+1],r-i+1);
        while(1+p[i]<=n&&i+p[i]<=m&&s[1+p[i]]==t[i+p[i]])p[i]++;
        if(i+p[i]-1>r)l=i,r=i+p[i]-1;  
    }
}
std::vector<int> zFunction(std::string s) {//0-base jiangly
    int n = s.size();
    std::vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = std::max(0, std::min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) {
            j = i;
        }
    }
    return z;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t>>s;
    t=' '+t,s=' '+s;
    int m=t.size()-1,n=s.size()-1;
    get_z(s,n);
    get_p(s,n,t,m);

    long long ans1=0,ans2=0;
    for(int i=1; i<=n; i++)
        ans1^=1LL*i*(z[i]+1);
    for(int i=1; i<=m; i++)
        ans2^=1LL*i*(p[i]+1);
    cout<<ans1<<endl<<ans2;
    return 0;
}