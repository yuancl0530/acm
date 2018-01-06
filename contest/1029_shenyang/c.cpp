/*********************************
Date: Sun Oct 29 12:47:52 CST 2017
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
const LL MOD = 2147493647;
const int maxn = 1e6 + 100;
struct Matrix
{
	int m,n;
	LL d[10][10];
	Matrix (int n=0,int m=0):n(n),m(m){CL(d);}
	void copy(LL *t)
	{
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j){
				d[i][j]=*t;
				++t;
			}
	}
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix c(a.n,b.m);
		for (int i=0;i<a.n;++i){
			for (int j=0;j<b.m;++j){
				LL tmp=0;
				for (int k=0;k<a.m;++k)
					tmp=(tmp+a.d[i][k]*b.d[k][j]%MOD)%MOD;
				c.d[i][j]=tmp;
			}
		}
		return c;
	}
};
LL solve (LL n1,LL n2,int n)
{
	Matrix a(1,7);
	Matrix b(7,7);
	if (n==1) return n2;
	if (n==2) return n1;
	LL aa[]={n2,n1,81,27,9,3,1};
	LL bb[]={
		1,1,0,0,0,0,0,
		2,0,0,0,0,0,0,
		1,0,1,0,0,0,0,
		0,0,4,1,0,0,0,
		0,0,6,3,1,0,0,
		0,0,4,3,2,1,0,
		0,0,1,1,1,1,1
	};
	a.copy(aa);
	b.copy(bb);
	n-=2;
	while (n){
		if (n&1)
			a=a*b;
		b=b*b;
		n>>=1;
	}
	return a.d[0][0];
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		LL a,b;
		int n;
		scanf("%d%lld%lld",&n,&a,&b);
		LL ans=solve(a,b,n);
		printf("%lld\n",ans);
	}
	return 0;
}
