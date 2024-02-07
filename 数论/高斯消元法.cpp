/*https://www.acwing.com/problem/content/description/885/*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
const int N=1e2+10;
const double eps=1e-8;
double a[N][N];
int n;
int gauss(){
    int c,r;
    for(c=1,r=1;c<=n;++c){
        int t=r;
        for(int i=r;i<=n;++i)//找绝对值最大的行
            if(fabs(a[i][c])>fabs(a[t][c]))
                t=i;
        if(fabs(a[t][c])<eps)continue;
        for(int i=c;i<=n+1;++i)swap(a[t][i],a[r][i]);// 将绝对值最大的行换到最顶端
        for(int i=n+1;i>=c;--i)a[r][i]/=a[r][c];// 将当前行的首位变成1
        for(int i=r+1;i<=n;++i){// 用当前行将下面所有的列消成0
            if(fabs(a[i][c])>eps){
                for(int j=n+1;j>=c;--j){
                    a[i][j]-=a[r][j]*a[i][c];
                }
            }
        }
        ++r;
    }
    if(r<=n){
        for(int i=r;i<=n;++i){
            if(fabs(a[i][n+1])>eps)return 2;
        }
        return 1;
    }
    for(int i=n;i>=1;--i){
        for(int j=i+1;j<=n;++j){
            a[i][n+1]-=a[i][j]*a[j][n+1];
        }
    }
    return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(2);
    
    
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            cin>>a[i][j];
        }
    }
    int t=gauss();
    if(t==2)cout<<"No solution"<<endl;
    else if(t==1)cout<<"Infinite group solutions"<<endl;
    else {
        for(int i=1;i<=n;++i)cout<<a[i][n+1]<<endl;
    }

    return 0;
}

