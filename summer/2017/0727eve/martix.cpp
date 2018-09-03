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
#define Cl(a,b) memset(a,b,sizeof(b))
#define INF 0x7fffffff
#define LL long long
const int maxn = 2e2 + 100;
int a[maxn][maxn];
int dp[2*maxn][maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	while (cin >> m >> n){
		CL(dp);
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		dp[1][1][1] =a[1][1];
		for (int s = 2;s < m + n;s++){
			int X1 = min(s,n);
			for (int x1 = X1;x1 >= 1;x1--){
				for (int x2 = x1;x2 >=1;x2--){
					int y1 = s + 1 - x1;
					int y2 = s + 1 - x2;
					dp[s][x1][x2] = max(max(dp[s-1][x1][x2],dp[s-1][x1-1][x2]),max(dp[s-1][x1][x2-1],dp[s-1][x1-1][x2-1]) ) + a[x1][y1] + (x1==x2? 0 :a[x2][y2]);
				//	printf("dp(%d,%d,%d) = %d\n",s,x1,x2,dp[s][x1][x2]);
				}
			}
		}
		cout << dp[m+n-1][n][n] <<endl;
	}
	return 0;
}
