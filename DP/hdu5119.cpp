/*********************************
Date: Fri Aug 25 08:36:46 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6+ 100;
LL dp[45][maxn];
int a[maxn];
int main()
{
	int n,m;
	int T;
	scanf("%d",&T);
	int t=0;
	while (T--){
		scanf("%d%d",&n,&m);
		CL(dp);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dp[0][0]=1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=1e6;j++){
				dp[i][j]+=dp[i-1][j];
				dp[i][j^a[i]]+=dp[i-1][j];
			}
		}
		LL ans=0;
		for (int i=m;i<=1e6;i++){
			ans+=dp[n][i];
		}
		printf("Case #%d: %lld\n",++t,ans);
	}


	return 0;
}
