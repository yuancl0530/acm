/*********************************
Date: Mon Jul 23 12:04:14 CST 2018
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
	int n;
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		ll ans = -1;
		if (n%3==0){
			n/=3;
			ans = (ll)n*n*n;
		}
		else if (n %4 == 0)
			ans = (ll)(n/2)*(n/4)*(n/4);
		printf("%lld\n",ans);
	}
	return 0;
}
