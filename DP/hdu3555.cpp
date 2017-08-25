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
LL dp[22][3];
int a[30];
int main()
{
	CL(dp);
	dp[0][0] = 1;
	for (int i = 1;i <= 21;i++){
		dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];  //don't have 49
		dp[i][1] = dp[i-1][0];   //don't have 49,with 9 on the first
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];   // have 49
	}
	LL n;
	int t;
	scanf("%d",&t);
	while (t--){
		LL ans = 0;
		int cnt = 0;
		scanf("%I64d",&n);
		n++;
		while (n){
			a[++cnt] = n % 10;
			n /= 10;
		}
		int last = 0;
		bool flag = 0;
		for (int i = cnt;i > 0;i--){
			ans += dp[i-1][2] * a[i];
			
			if (!flag && a[i] > 4){
				ans += dp[i-1][1];
			}
			if (flag){
				ans += dp[i-1][0]*a[i]; 
			}
			if (last == 4 && a[i] == 9){
				flag = 1;
			}
			last = a[i];
		}
		printf("%I64d\n",ans);

	}
	return 0;
}
