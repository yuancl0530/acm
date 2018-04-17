/*********************************
Date: Tue Apr 17 17:13:09 CST 2018
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
int num[maxn];
int main()
{
	int n,t;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&t);
		++num[t];
	}
	LL ans = 0;
	for (int i=0;i<=200000;++i){
		ans += num[i]/2;
	}
	ans >>= 1;
	printf("%lld\n",ans);
	return 0;
}
