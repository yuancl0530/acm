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
const int maxn = 1e3 + 100;
LL c[maxn][maxn];
void init()
{
	c[0][0] = 1;
	for (int i = 1;i <= 1000;i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1;j < i;j++){
			c[i][j] =( c[i-1][j] + c[i-1][j-1])%MOD;
		}
	}
}
int a[maxn];
int main()
{
	int n;
	init();
	while (scanf("%d",&n) != EOF){
		LL sum = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			sum += a[i];
		}
		LL ans = 1;
		for (int i = n;i > 0;i--){
			ans = ans * c[sum-1][a[i]-1] % MOD;
			sum -= a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
