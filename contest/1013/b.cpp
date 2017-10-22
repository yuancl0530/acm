/*********************************
Date: Fri Oct 13 19:11:25 CST 2017
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
	LL n,k;
	while (scanf("%lld%lld",&n,&k) !=EOF){
		LL ma,mi;
		if (3*k>=n){
			ma=n-k;
		}
		else{
			ma=2*k;
		}
		if (n==k || k==0) mi=0;
		else mi=1;
		printf("%lld %lld\n",mi,ma);
	
	}
	return 0;
}
