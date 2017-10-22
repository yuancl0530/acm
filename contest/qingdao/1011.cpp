/*********************************
Date: Sun Sep 17 12:22:07 CST 2017
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
bool check(LL n)
{
	LL t=sqrt(n);
	if ((n-1)%3!=0) return false;
	n=(n-1)/3;
	for (LL i=1;i<t;++i){
		if (i*(i+1)==n)
			return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		LL p;
		scanf("%lld",&p);
		if (check(p))
			printf("YES\n");
		else
			printf("NO\n");
	}



	return 0;
}
