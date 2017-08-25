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
const int maxn = 1e3 + 1;
const int maxm = 2e4 + 1;
int dp[maxn][maxm];
int main()
{
	for (int i = 0;i <= 1000;i++){
		dp[i][0] = 1;
	}
	dp[1][0] = 1;
	for (int i = 1;i <= 1000;i++){
		for (int j = 1;j <= 20000;j++){
			if (j>=i){
				dp[i][j] = (0ll + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]+MOD)%MOD;
			}
			else{
				dp[i][j] = (0ll + dp[i][j-1] + dp[i-1][j])%MOD;
			}
		}
	}
	int n,k;
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		if (k > n*(n-1)/2){
			printf("0\n");
		}
		else{
			printf("%d\n",dp[n][k]);
		}
	}
	return 0;
}
