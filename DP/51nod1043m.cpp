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
const int maxn = 1e4;
const int MOD = 1e9 + 7;
LL dp[1010][maxn];
int main()
{
	for (int i = 1;i <= 9;i++){
		dp[1][i] = 1;
	}
	for (int i = 2;i <= 1000;i++){
		for (int j = 1;j <= 9*i;j++){
			int k = (j-10)>=0? j-10:0;
			dp[i][j] = (dp[i][j-1] - dp[i-1][k] + dp[i-1][j]+MOD) % MOD;
		}
	}
	int n;
	LL ans;
	//cout << dp[4][36] <<endl;
	while (scanf("%d",&n) != EOF){
		ans = 0;
		for (int i = 1;i <= n*9;i++){
			for (int j = 1;j <= n;j++){
				ans = (ans + dp[n][i] * dp[j][i]) % MOD;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
