/*********************************
Date: Fri Sep 15 19:02:31 CST 2017
*********************************/
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL Pow(LL n)
{
	LL ans=1;
	LL t=2;
	while (n){
		if (n&1)
			ans*=t;
		t=t*t;
		n>>=1;
	}
	return ans;
}
int main()
{
	int T;
	LL n;
	scanf("%d",&T);
	while (T--){
		LL ans=0;
		scanf("%lld",&n);
		ans=(n+1)*n/2;
		LL t=log2(n);
		LL tmp=2*(Pow(t+1)-1);
		ans-=tmp;
		printf("%lld\n",ans);
	}
	return 0;
}
