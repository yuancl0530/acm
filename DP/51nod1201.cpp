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
const int maxn = 5e4 + 10;
const int maxm = 320 + 10;
LL dp[maxn][maxm];
int main()
{
	dp[1][1] = 1;
	for (int i = 1;i <= 50000;i++){
		for (int j = 1;j <= 320;j++){
			if (i>j)
				dp[i][j] = (dp[i-j][j-1] + dp[i-j][j]) % MOD;
		}
	}
	int n;
	while (scanf("%d",&n) != EOF){
		LL ans = 0;
		for (int i = 1;i <= 320;i++){
			ans = (ans + dp[n][i]) % MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
