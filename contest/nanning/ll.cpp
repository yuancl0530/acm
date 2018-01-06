/*********************************
Date: Mon Sep 25 15:01:39 CST 2017
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
const int maxn = 1e6 + 100;
int a[maxn];
int f[maxn];
int cnt=0;
int main()
{
	int n;
	int ans=0;
	while (scanf("%d",&n)!=EOF){
		if (n<0)
			continue;
		if (n<=10000)
			a[++cnt]=n;
		else{
			for (int i=0;i<5;++i)
				a[++cnt]=n%1000;
		}
	
	}
	f[0]=0;
	for (int i=1;i<=cnt;++i){
		for (int j=i;j>0;--j)
			if (a[i]>=a[j])
				f[i]=max(f[i],f[j]+1);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}

