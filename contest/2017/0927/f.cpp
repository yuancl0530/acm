/*********************************
Date: Mon Sep 25 15:01:39 CST 2017
最长非递减子序列O（log n)做法
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
int a[maxn];
int f[maxn];
int n;
int binsearch(int *f,int v)
{
	int l=1;
	int r=n+1;
	int mid;
	while (l<r){
		mid=(l+r)>>1;
		if (v>=f[l-1]&&v<f[l])
			return l;
		if (v>=f[mid])
			l=mid+1;
		else
			r=mid;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=1;
		Cl(f,0x3f);
		f[0]=-INF;
		for (int i=1;i<=n;++i){
			int t=binsearch(f,a[i]);
			f[t]=min(f[t],a[i]);
			ans=max(t,ans);
		}
		Cl(f,0x3f);
		a[0]=-INF;
		for (int i=n;i>0;--i){
			int t=binsearch(f,a[i]);
			f[t]=min(f[t],a[i]);
			ans=max(t,ans);
		}
		if (ans>=n-1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
