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
int a[maxn];
LL sum[maxn];
int main()
{
	int n;
	LL sum,ans;
	while (scanf("%d",&n) != EOF){
		ans = sum = 0;
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
		}
		for (int i = 1;i <= n;i++){
			sum = max(sum+a[i],0ll);
			ans = max(sum,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
