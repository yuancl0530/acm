/*********************************
Date: Thu Nov 16 20:27:57 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL f[maxn],m;
LL check(LL t)
{
	LL sum=0;
	for (int i=2;;++i){
		sum+=t/f[i];
		if (sum>m) break;
		if (t/f[i]==0)break;
	}
	return sum;
}
int main()
{
	for (LL i=1;i<=1e5+1;++i)
		f[i]=i*i*i;
	scanf("%lld",&m);
	LL l=7;
	LL r=1e18;
	LL mid;
	LL ans=1<<31;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)>=m){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	if (check(r)==m)
		printf("%lld\n",r);
	else
		printf("-1\n");
	return 0;
}
