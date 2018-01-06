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

int main()
{
	int T;
	int t = 0;
	scanf("%d",&T);
	while (T--){
		LL n;
		scanf("%lld",&n);
		LL ans = (n+2)*(n-1)/2;
		printf("Case #%d: %lld\n",++t,ans);
	}
	return 0;
}
