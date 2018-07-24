/*********************************
Date: Thu Apr 26 08:33:26 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
ll Pow(ll a,int n)
{
	ll res = 1;
	while (n){
		if (n&1) {
			res = (res*a) % mod;
		}
		a = a*a%mod;
		n>>=1;
	}
	return res;
}
ll solve(int n,int k)
{
	ll ans = 0;
	for (int i=1;i<=n;++i){
		ans = (ans+Pow(i,k))%mod;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,k;
		scanf("%d%d",&n,&k);
		ll ans = solve(n,k);
		printf("%lld\n",ans);
	}
	return 0;
}
