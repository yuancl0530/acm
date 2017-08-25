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
const int maxn = 1e6 + 100;
int b[maxn];
int dp[maxn][2];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i = 1;i <= n;i++){
			scanf("%d",&b[i]);
		}
		CL(dp);
		for (int i = 2;i <= n;i++){
			dp[i][0] = max(dp[i-1][0],dp[i-1][1]+b[i-1]-1);
			dp[i][1] = max(dp[i-1][0]+b[i]-1,dp[i-1][1]+abs(b[i]-b[i-1]));
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}
