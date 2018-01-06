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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e2 + 100;
int dp[maxn][maxn];
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		CL(dp);
		int ans = 0;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= i;j++){
				scanf("%d",&dp[i][j]);
				dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
				ans = max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
