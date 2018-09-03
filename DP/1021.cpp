/*********************************
Date: Wed Nov 22 16:20:26 CST 2017
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
const int maxn = 1e4 + 100;
int sum[110],a[110];
int dp[maxn][110];
int n,m;
void solve()
{
	sum[0]=0;
	for (int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
		dp[1][i]=0;
	}
	for (int len=2;len<=n;++len){//length 
		for (int i=1;i+len-1<=n;++i){
			dp[len][i]=INF;
			for (int j=1;j<len;++j)
				dp[len][i]=min(dp[j][i]+dp[len-j][i+j]+sum[i+len-1]-sum[i-1],dp[len][i]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	solve();
	printf("%d\n",dp[n][1]);
	return 0;
}
