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
const int maxn = 1e3 + 100;
int a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	int n;
	LL ans;
	while (scanf("%d",&n) != EOF){
		CL(dp);
		CL(a);
		ans = 0;
		for (int i = 1;i <= n;i++){
			for (int j =1;j <= i;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= i;j++){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
				ans = max(ans,(LL)dp[i][j]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
