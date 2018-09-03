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
const int maxn = 1e6 + 100;
LL dp[11][10];//i bits with j first 
int a[15];
int f[15];
int main()
{
	int n;
	f[0] = 1;
	for (int i = 1;i <= 10;i++){
		f[i] = f[i-1] * 10;
	}
	for (int i = 1;i <= 10;i++){
		dp[i][0] = dp[i-1][9] + 1;
		for (int j = 1;j <= 9;j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][9];
			if (j == 1){
				dp[i][j] = dp[i][j] + f[i-1] - 1;
			}
		}
	}
	//cout << dp[3][1] << endl;
	while (scanf("%d",&n) != EOF){
		int cnt = 0;
		int p = n;
		while (n){
			a[++cnt] = n % 10;
			n /= 10;
		}
		LL ans = 0;
		for (int i = cnt;i > 0;i--){
			if (a[i]){
				ans += dp[i][a[i]-1];
				if (a[i] == 1){
					ans += p % f[i-1];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
