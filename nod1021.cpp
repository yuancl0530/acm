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
const int maxn = 1e2 + 100;
int a[maxn];
LL dp[maxn][maxn];
LL sum[maxn][maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		Cl(dp,0);
		CL(sum);
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		for (int i = 1;i <= n;i++){
			for (int j = i;j <=n;j++){
				for (int k = i;k <= j;k++){
					sum[i][j] += a[k];
				}
			}
		}
		for (int len = 2;len <= n;len++){
			for (int i = 1;i + len <= n+1;i++){
				int j = i + len -1;
				dp[i][j] = dp[i][i] + dp[i+1][j] + sum[i][j];
				for (int k = i;k < j;k++){
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + sum[i][j]);
				}
//				printf("dp(%d,%d)=%lld\n",i,j,dp[i][j]);
			}
		}
		printf("%lld\n",dp[1][n]);
	}
	return 0;
}
