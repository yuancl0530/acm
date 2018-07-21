/*********************************
Date: Thu Jul 19 12:12:35 CST 2018
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
int n,m;
ll qpow(ll a, int n)
{
	ll ret = 1;
	while (n) {
		if (n&1)
			ret = ret*a%m;
		a = a * a % m;
		n >>= 1;
	}
	cout<<ret<<endl;
	return ret;
}
ll a[maxn];
int main()
{
	n = 5;
	m = 1e9;
//	ll ans = qpow(n-1,n-2) - qpow(n-1,n-3);
//	ans = (ans+m)%m;
	a[4] = 6;
	a[5] = 22;
	for (int i = 6;i <= 100000;++i){
		a[i] = a[i-1]*a[i-2]%m;
		a[i] = (a[i]-2+m)%m;
	}
	cout << a[6] <<endl;
	cout << a[7] <<endl;
	cout << a[100000] <<endl;
	return 0;
}
