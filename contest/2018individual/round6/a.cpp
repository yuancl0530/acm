/*********************************
Date: Wed Apr 11 19:02:04 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int n;
	scanf("%d",&n);
	int mi=n/7;
	mi*=2;
	n%=7;
	int ma;
	if (n>=2)
		ma=mi+2;
	else if (n==1)
		ma=mi+1;
	else 
		ma=mi;
	if (n==6)
		mi+=1;
	printf("%d %d\n",mi,ma);
	return 0;
}
