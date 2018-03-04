/*********************************
Date: Mon Nov 13 14:34:47 CST 2017
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
char s[maxn],t[maxn];
int dp[maxn][maxn][15][2];
int n,m,k;
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	CL(dp);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			for (int p=1;p<=k;++p){
				if (s[i+1]==t[j+1]){
					dp[i][j][p][0]=max(dp[i-1][j-1][p][0],dp[i-1][j-1][p-1][1])+1;
				}
				dp[i][j][p][1]=max(max(dp[i-1][j][p][1],dp[i][j-1][p][1]),dp[i][j][p][0]);
			}
		}
	}
	int ans=max(dp[n][m][k][0],dp[n][m][k][1]);
	printf("%d\n",ans);
	return 0;
}
