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
const int MOD = 1e9 + 7;
LL dp[maxn];
int pos[maxn];
int a[maxn];
int main()
{
	int n;
	ios::sync_with_stdio(false);
	while (cin >> n){
		CL(pos);
		CL(dp);
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		dp[0] = 1;
		for (int i = 1;i <= n;i++){
			dp[i] =( 2 * dp[i-1] )%MOD;
			if (pos[a[i]]){
				dp[i] = (dp[i] - dp[pos[a[i]]-1] + MOD) % MOD;
			}
			pos[a[i]] = i;
		}
		cout << dp[n] - 1 <<endl;
	}
	return 0;
}
