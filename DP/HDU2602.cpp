#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
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
#define INF 0x7fffffff
const int maxn = 1e3+10;
int dp[maxn][maxn];
int value[maxn],volume[maxn];
int main()
{
	int t;
	int n,v;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&v);
		CL(value);
		CL(volume);
		for (int i = 1;i <= n;i++)
			scanf("%d",&value[i]);
		for (int i = 1;i <= n;i++)
			scanf("%d",&volume[i]);
		CL(dp);
		for (int i = 1;i <= n;i++){
			for (int j = 0;j <= v;j++){
				if(j >= volume[i])
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-volume[i]] 
					+ value[i]);
				else 
					dp[i][j] = dp[i-1][j];
			}
		}
		printf("%d\n",dp[n][v]);
	}
	return 0;
}
