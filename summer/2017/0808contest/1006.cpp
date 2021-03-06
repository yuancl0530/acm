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

int main()
{
	LL n,m;
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		LL ans;
		if (m <= n-1){
			ans = 2*m+2*m*(m-1) + (n-1-m)*(n-1)*n + (m+1)*n*(n-m-1);
		}
		else{
			ans = 2*(n-1) + 2*(n-1)*(n-2) - 2*min(m-(n-1),(n-1)*(n-2)/2);
		}
		printf("%lld\n",ans);
	
	}
	return 0;
}
