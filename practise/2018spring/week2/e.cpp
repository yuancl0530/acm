/*********************************
Date: Mon Mar 12 12:25:58 CST 2018
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
const int maxn = 1e6 + 10;
LL cat[maxn];
LL inv[maxn];
LL c[maxn];
void init()
{
	inv[1] = 1;
	for (int i=2;i<maxn;++i)
		inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
	cat[0] = 1;
	for (int i=1;i<maxn;++i)
		cat[i] = (4*i-2)*cat[i-1]%MOD*inv[i+1]%MOD;
}

int solve(int n)
{
	int k=0;
	int ret=1;
	c[0] = 1;
	c[1] = n;
	for (int i=2;i<=n;++i)
		c[i] = c[i-1]*(n-i+1)%MOD*inv[i]%MOD;
	for (int i=1;i<=n/2;++i){
		k = n-2*i;
		LL tmp = cat[i]*c[k]%MOD;
		ret = (tmp+ret)%MOD;
	}
	return ret;
}
int main()
{
	init();
	int T;
	scanf("%d",&T);
	int n;
	while (T--){
		scanf("%d",&n);
		printf("%d\n",solve(n));
	}
}
