/*********************************
Date: Wed Nov 22 15:19:40 CST 2017
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
const int maxn = 5e3 + 100;
int a[maxn];
LL dp[2][maxn][2];//0 on 1 not 
int n,m;
void solve()
{
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j){
			dp[i&1][j][1]=max(dp[i&1][j-1][1],max(dp[(i-1)&1][j-1][1],dp[(i-1)&1][j-1][0]))+a[j];
			dp[i&1][j][0]=max(dp[i&1][j-1][1],dp[i&1][j-1][0]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	solve();
	printf("%lld\n",max(dp[m&1][n][0],dp[m&1][n][1]));
	return 0;
}
