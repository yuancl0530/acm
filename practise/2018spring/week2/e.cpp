/*********************************
Date: Fri Mar  9 12:04:22 CST 2018
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
LL dp[maxn];
LL t[maxn];
void init()
{
	t[0]=0;
	for (int i=1;i<=1000000;++i){
		if (i&1)
			t[i] = t[i-1];
		else
			t[i] = (t[i-1]+i)%MOD;
	}
	dp[1] = 1;
	dp[2] = 2;
	for (int i=3;i<=1000000;++i){
		dp[i] = (t[i-1]+1)*dp[i-1]%MOD;
	}
}
int main()
{
	init();
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}
