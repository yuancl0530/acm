/*********************************
Date: Fri Mar  9 14:55:22 CST 2018
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
const int MOD = 1e5 + 7;
const int maxn = 1e3 + 100;
int dp[maxn][maxn];
char s[maxn];
int solve()
{
	int n=strlen(s+1);
	for (int i=1;i<=n;++i)
		dp[i][i]=1;
	for (int len=2;len<=n;++len){
		for (int i=1;i+len-1<=n;++i){
			int l=i;
			int r=i+len-1;
			dp[l][r] = (dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+MOD)%MOD;
			if (s[l] == s[r]){
				dp[l][r] = (dp[l][r]+dp[l+1][r-1]+1)%MOD;
			}
		}
	}
	return dp[1][n];
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i){
		scanf("%s",s+1);
		printf("Case #%d: %d\n",i,solve());
	}
	return 0;
}
