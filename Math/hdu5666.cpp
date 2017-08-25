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
LL MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL solve(LL a,LL b)
{
	LL ret = 0;
	if (b==0)return 0;
	while (b > 1){
		if (b&1)
			ret = (ret + a) % MOD;
		a = 2*a%MOD;
		b>>=1;
	}
	ret = (ret + a)%MOD;
	return ret;
}
int main()
{
	LL p,q;
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%lld%lld",&q,&p);
		MOD = p;
		q -= 2;
		LL a = q + 1;
		LL b = q;
		if (a&1)b>>=1;
		else a>>=1;
		LL ans = solve(a,b);
		printf("%lld\n",ans);
	}

	return 0;
}
