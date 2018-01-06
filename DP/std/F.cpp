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
const int maxn = 5e4 + 100;
int a[maxn];
int dp[maxn];
int main()
{
	int n,t,ans;
	while (scanf("%d",&n) != EOF){
		Cl(dp,0x7f);
		dp[0] = -INF;
		ans = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		for (int i = 1 ;i <= n;i++){
			t = lower_bound(dp+1,dp+n+2,a[i]) - dp;
			ans = max(ans,t);
			dp[t] = min(dp[t],a[i]);
		}
		printf("%d\n",ans);
		}
	return 0;
}

