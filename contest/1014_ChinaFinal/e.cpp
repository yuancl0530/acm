/*********************************
Date: Mon Oct 16 12:02:43 CST 2017
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
const int maxn = 2e3 + 100;
#define N 1000
int c[110][maxn],sum[maxn];
int Rank[maxn];
void div(int x,int y,int *c)//高精度除法，0.xxxxxxx
{
	for (int i=0;i<=N+1;++i){
		x*=10;
		c[i]=x/y;
		x%=y;
		if (!x) break;
	}
	if (c[N+1]>=5)c[N]++;
}
bool cal_sum(int *a,int *b)//高精度加法，结果>=1返回true
{
	int c=0;
	for (int i=N;i>=0;--i){
		a[i]=a[i]+b[i]+c;
		c=a[i]/10;
		a[i]%=10;
	}
	return c;
}
bool cmp(int a,int b)
{
	for (int i=0;i<=N;++i){
		if (c[a][i]!=c[b][i])
			return c[a][i]<c[b][i];
	}
	return c[a][N]<c[b][N];
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt){
		int n;
		double a,b;
		CL(sum);
		CL(c);
		for (int i=1;i<=N;i++) Rank[i]=i;
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%lf:%lf",&a,&b);
			int aa=floor(a*1000+0.5);
			int bb=floor(b*1000+0.5);
			div(aa,aa+bb,c[i]);
		}
		sort(Rank+1,Rank+1+n,cmp);
		int ans=0;
		for (int i=1;i<=n;++i){
			if (cal_sum(sum,c[Rank[i]]))
				break;
			else
				++ans;
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
