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
LL sum[maxn];
int main()
{
	int n,a;
	LL sum,ans;
	while (scanf("%d",&n) != EOF){
		ans = sum = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a);
			sum = max(sum+a,0ll);
			ans = max(sum,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

