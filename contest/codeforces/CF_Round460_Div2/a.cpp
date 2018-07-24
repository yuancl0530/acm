/*********************************
Date: Wed Jan 31 21:04:53 CST 2018
Author: ycl
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

int main()
{
	double ans = INF;
	int n,m;
	scanf("%d%d",&n,&m);
	double a,b;
	for (int i=0;i<n;++i){
		scanf("%lf%lf",&a,&b);
		ans = min(ans,m*a/b);
	}
	printf("%lf\n",ans);
	return 0;
}
