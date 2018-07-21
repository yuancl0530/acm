/*********************************
Date: Sat Jul  7 14:05:14 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int T;
	scanf("%d",&T);
	for (int k =1;k <= T;++k){
		ll n;
		scanf("%lld",&n);
		ll ans = (2+n)*(n-1)/2;
		printf("Case #%d: %lld\n",k,ans);
	}
	return 0;
}
