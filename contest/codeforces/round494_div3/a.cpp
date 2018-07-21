/*********************************
Date: Tue Jul  3 22:36:36 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e2 + 100;
int a[maxn];
int main()
{
	int n;
	int ans = 0;
	scanf("%d",&n);
	int t;
	for (int i = 0;i < n;++i){
		scanf("%d",&t);
		ans = max(ans,++a[t]);
	}
	printf("%d\n",ans);
	return 0;
}
