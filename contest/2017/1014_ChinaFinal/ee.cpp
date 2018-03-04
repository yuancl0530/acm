/*********************************
Date: Mon Oct 16 13:44:39 CST 2017
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
const int maxn = 1e3 + 100;
const int N=1000;
struct xiaoshu//0.xxxxxx
{
	int v[maxn];
	void div(int x,int y)
	{
		for (int i=0;i<=N+1;++i){
			x*=10;
			v[i]=x/y;
			x%=y;
			if (!x)break;
		}
		if (v[N+1])++v[N];
	}
	bool add(xiaoshu b)//>=1返回0
	{
		int c=0;
		for (int i=N;i>=0;--i){
			v[i]=v[i]+b.v[i]+c;
			c=v[i]/10;
			v[i]%=10;
		}
		return c;
	}
	friend bool operator <(xiaoshu a,xiaoshu b)
	{
		for (int i=0;i<=N;++i){
			if (a.v[i] != b.v[i])
				return a.v[i]<b.v[i];
		}
		return false;
	}
}c[110],s;
int main()
{
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;++tt){
		int n;
		double a,b;
		CL(s.v);
		CL(c);
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			scanf("%lf:%lf",&a,&b);
			int aa=floor(a*1000+0.5);
			int bb=floor(b*1000+0.5);
			c[i].div(aa,aa+bb);
		}
		sort(c+1,c+1+n);
		int ans=0;
		for (int i=1;i<=n;++i){
			if (s.add(c[i]))
				break;
			else
				++ans;
		}
		printf("Case #%d: %d\n",tt,ans);
	}



	return 0;
}
