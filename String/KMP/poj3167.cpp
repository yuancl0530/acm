/*********************************
Date: Tue Nov 21 20:34:32 CST 2017
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int tot[maxn],Next[maxn],cow[maxn],ans[maxn],p[maxn],p1[maxn],p2[maxn];
int n,m,k,s,cnt;
int lowbit(int x){return -x&x;}
int sum(int pos)
{
	int ret=0;
	while (pos>0){
		ret+=tot[pos];
		pos-=lowbit(pos);
	}
	return ret;
}
void update(int pos,int v)
{
	while (pos<=s){
		tot[pos]+=v;
		pos+=lowbit(pos);
	}
}
void getNext()
{
	int k=0;
	CL(tot);
	for (int i=1;i<=m;++i){
		p1[i]=sum(p[i]-1);
		p2[i]=sum(p[i]);
		update(p[i],1);
	}
	CL(tot);
	Next[1]=k;
	for (int i=2;i<=m;++i){
		while (k>1 && (sum(p[i]-1) != p1[k+1] || sum(p[i]) != p2[k+1]))	{
			for (int j=i-k;j<i-Next[k];++j)
				update(p[j],-1);
			k=Next[k];
		}
		if (sum(p[i]-1) == p1[k+1] && sum(p[i]) == p2[k+1])
			++k;
		Next[i]=k;
		update(p[i],1);
	}
}
void KMPmatch()
{
	getNext();
	CL(tot);
	cnt=0;
	int k=0;
	for (int i=1;i<=n;++i){
		while (k>0 && (sum(cow[i]-1)!=p1[k+1] || sum(cow[i]) != p2[k+1])){
			for (int j=i-k;j<i-Next[k];++j)
				update(cow[j],-1);
			k=Next[k];
		}
		if (sum(cow[i]-1) == p1[k+1] && sum(cow[i]) == p2[k+1])
			++k;
		if (k==m){
			ans[cnt++]=i-m+1;
			for (int j=i-k+1;j<=i-Next[k];++j)
				update(cow[j],-1);
			k=Next[k];
		}
		update(cow[i],1);
	}

}
int main()
{
	while (scanf("%d%d%d",&n,&m,&s)!=EOF){
		for (int i=1;i<=n;++i)
			scanf("%d",cow+i);
		for (int i=1;i<=m;++i)
			scanf("%d",p+i);
		KMPmatch();
		printf("%d\n",cnt);
		for (int i=0;i<cnt;++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}
