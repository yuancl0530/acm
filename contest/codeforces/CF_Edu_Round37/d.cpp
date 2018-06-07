/*********************************
Date: Sat Feb  3 00:10:26 CST 2018
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
int b[maxn];
int dp[5010];
int main()
{
	int n,k,v;
	scanf("%d%d%d",&n,&k,&v);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[i]=a[i]%k;
	}
	int vv=v%k;
	dp[0]=1;
	for (int i=1;i<=n;++i){
		if (b[i] == 0) continue;
		for (int j=vv;j>=1;--j){
			if (j-b[i]>=0 && dp[j-b[i]])
				dp[j] = i; 
		}
	}
	if (dp[vv]==0)
		printf("NO\n");
	int t=vv;
	while (vv){
		printf("%d\n",dp[vv]);
		vv=dp[vv];
	}

	return 0;
}
