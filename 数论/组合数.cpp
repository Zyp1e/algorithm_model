#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
const int N=1e4+10;
const int mod=1e9+7,p=1e9+7;
//1.数据量大，a,b值小
int c[N][N];
void init1(){
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){//注意是<=
			if(!j) c[i][j]=1;//初始化
			else c[i][j]=c[i-1][j]+c[i-1][j-1];//递推公式
		}
	}
}


//2.数据量小，a,b值较大

int fact[N],infact[N];
int qmi(int a,int k,int p){//快速幂
	int res=1;
	while(k){
		if(k&1) res=res*a%p;
		k>>=1;
		a=a*a%p;
	}
	return res;
}
 
void init2(){//预处理阶乘数组和乘法逆元数组
	fact[0]=infact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=fact[i-1]*i%mod;
		infact[i]=infact[i-1]*qmi(i,mod-2,mod)%mod;//用快速幂求乘法逆元
	}
}
int get(int a,int b){//Ca取b
    int res=fact[a]*infact[b]%mod*infact[a-b]%mod;//代入公式求解组合数
    return res;
}


//3.a,b非常大，仅求同模p的值
int C(int a,int b){
	int res=1;
	for(int i=1,j=a;i<=b;i++,j--){
		res=res*j%p;
		res=res*qmi(i,p-2,p)%p;//除以一个数转化为乘它的乘法逆元
	}
	return res;
}
 
int lucas(int a,int b){
	if(a<p&&b<p) return C(a,b);//a,b都小于p，定义求解
	return C(a%p,b%p)*lucas(a/p,b/p)%p;//代入卢卡斯公式
}

//4.a,b非常大，求具体值
int primes[N],cnt=0;
bool st[N];
int sum[N];//储存质因数个数
 
 
void get_primes(int n){//线性筛法分解质因数
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;	
		for(int j=0;primes[j]<=n/i;j++){
			st[primes[j]*i]=true;
			if(i%primes[j]==0) break;
		}		
	}
}
 
int get(int n,int p){//求质因数个数
	int res=0;
	while(n){
		res+=n/p;
		n/=p;
	}
	return res;
}
 
vector<int> mul(vector<int> &A,int b){//高精度乘法
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size()||t;i++){
		if(i<A.size()) t+=A[i]*b;
		C.push_back(t%10);
		t/=10;
	}
	return C;
}
 
signed main(){
    int a,b;
	cin>>a>>b;
 
	get_primes(a);//分解分子的质因数
 
	for(int i=0;i<cnt;i++){
		int p=primes[i];
		sum[i]=get(a,p)-get(b,p)-get(a-b,p);//分子、分母中消去相同质因数p后的个数
	}
 
	vector<int> res;
	res.push_back(1);
	for(int i=0;i<cnt;i++){
		for(int j=0;j<sum[i];j++){
			res=mul(res,primes[i]);
		}
	}
	for(int i=res.size()-1;i>=0;i--) cout<<res[i];
	
	return 0;
}


//5.卡特兰数