/*https://codeforces.com/problemset/problem/213/E*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long int64;
const int N=2e5+10,D=200003;
typedef pair<int,int>pp;
int a[N],b[N],pos[N];
int64 d[N];
struct info{
	int res;
    int64 num;
}; 
struct Node{
	info val;
}node[N*4];
info operator +(const info &a,const info &b){
	info temp;
    temp.res=a.res+b.res;
    temp.num=a.num*d[b.res]+b.num;
    return temp;
}
void update(int id){
	node[id].val=node[id*2].val+node[id*2+1].val;
}
void change(int id,int l,int r,int pos,int dd){
	if(l==r){
		node[id].val={dd?node[id].val.res+1:node[id].val.res-1,(int64)dd};
	}else {
		int mid=(l+r)>>1;
		if(pos<=mid)change(id*2,l,mid,pos,dd);
		else change(id*2+1,mid+1,r,pos,dd);
		update(id);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int64 sum=0,aa=0;
    d[0]=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum=sum*D+a[i];
        d[i]=d[i-1]*D;
        aa+=d[i-1];
    }
    for(int i=1;i<=m;++i){
        cin>>b[i];
        pos[b[i]]=i;
    }
    int cnt=0;
    for(int i=1;i<=m;++i){
        if(i>n)change(1,1,m,pos[i-n],0);
        change(1,1,m,pos[i],i);
        if(i>=n&&node[1].val.num==(i-n)*aa+sum)
            ++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}