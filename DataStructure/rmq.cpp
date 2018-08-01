/*********************************
Date: Fri May 25 18:29:27 CST 2018
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
int s[maxn][20],a[maxn];
int Log[maxn],n;
void init()
{
	for (int i = 2;i < maxn;++i)
		Log[i] = Log[i/2] + 1;
	for (int i = 1;i <= n;++i)
		s[i][0] = a[i];
	for (int j = 1;(1<<j) <= n;++j){
		for (int i = 1;i+(1<<j)-1<=n;++i)
			s[i][j] = max(s[i][j-1],s[i+(1<<(j-1))][j-1]);
	}
}
int query(int l,int r)
{
	int k = Log[r-l+1];
	return max(s[l][k],s[r+1-(1<<k)][k]);
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	init();
	int l,r;
	while (m--){
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
