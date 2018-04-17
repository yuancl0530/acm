/*********************************
Date: Sun Apr 15 13:27:40 CST 2018
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
LL quick_pow(LL a,LL n)
{
	LL ret=1;
	while (n){
		if (n&1){
			ret=ret*a%mod;
		}
		a=a*a%mod;
		n>>=1;
	}
	return ret;
}
void exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0){
		x=1;
		y=0;
		return ;
	}
	exgcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
}
LL inv(LL a)
{
	LL x,y;
	exgcd(a,mod,x,y);
	return (x+mod)%mod;
}
int main()
{
	LL n;
	LL t=inv(2);
	while (scanf("%lld",&n)!=EOF){
		LL ans;
		if (n%4==0 || (n-1)%4==0){
			ans=n*(n-1)/4;
		}
		else{
			ans=n*(n-1)/2%mod*t%mod*quick_pow(2,mod-2)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
