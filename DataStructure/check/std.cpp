/*********************************
Date: Tue Jul 31 18:31:26 CST 2018
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
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	printf("%d\n",a[n/2]);
	return 0;
}
