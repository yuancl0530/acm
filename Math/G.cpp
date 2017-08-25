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
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[400];
int dp[400];
int main()
{
	int n,t;
	while (cin >> n >>t){
		CL(dp);
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		int ans = 0;			
		for (int i = 1;i <= n;i++){
			int j = i-1;
			while (j >= 0){
				if (a[i] >= a[j])
					dp[i] = max(dp[i],dp[j] + 1);
				--j;
			}
			ans = max(ans,dp[i]);
		}
		for (int k =2 ;k <= min(100,t);k++){
			for (int i = 1;i <= n;i++){
				int t = dp[i];
				for (int j = 1;j <= n;j++){
					if (a[j] <= a[i] && i!=j)
						dp[i] = max(dp[i],dp[j]+1);
				}
				dp[i] = max(dp[i],t+1);
				ans = max(ans,dp[i]);
			}
		}
		if (t > 100){
			int tt = 0;
			for (int i = 1;i <= n;i++){
				int t = dp[i];
				for (int j = 1;j <= n;j++){
					if (a[j] <= a[i] && i!=j)
						dp[i] = max(dp[i],dp[j]+1);
				}
				dp[i] = max(dp[i],t+1);
				tt = max(tt,dp[i]);
			}
			ans += (t-100)*(tt-ans);
		}
		cout << ans << endl;
	}
	return 0;
}
