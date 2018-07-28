/*********************************
Date: Fri Jul 27 18:55:23 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
ll n,k,m;
int l;
ll qpow(ll a,ll n)
{
	ll ret = 1;
	while (n){
		if (n&1)
			ret = ret * a % m;
		a = a * a %m;
		n >>= 1;
	}
	return ret;
}
int main()
{
	scanf("%lld%lld%d%lld",&n,&k,&l,&m);
	int n1 = 0;
	for (int i = l-1;i >= 0;--i){
		if ((k>>i) & 1) ++n1;
	}
	ll t1 = (qpow(2,n-1) - 1 + m) % m ;
	ll t2 = (qpow(2,n) - t1 + m) % m;
	t1 = qpow(t1,n1);
	t2 = qpow(t2,l-n1);
	ll ans = t1*t2%m;
	printf("%lld\n",ans);
	return 0;
}
