/*********************************
Date: Tue Jul  3 23:22:38 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int a[maxn];
int sum[maxn];
int m[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i =1;i <= n;++i) {
		scanf("%d",&a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= i;++j)
			m[j] = max(m[j],sum[i]-sum[i-j]);
	}
	double ans = 0;
	for (int i = k;i <= n;++i)
		ans = max(ans,(double)m[i]/i);
	printf("%.9lf\n",ans);
	return 0;
}
