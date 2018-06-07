/*********************************
Date: Mon May 28 23:00:00 CST 2018
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
int p[maxn],len[maxn];
int solve(int l,int r)
{
	int ret = 0;
	int t = p[l];
	while (l <= r){
		if (p[l] > t)
			ret += p[l] - t;
		t = max(t,p[l]+len[l]);
		++l;
	}
	return ret;
}
int main()
{
	int n,q;
	cin >> n;
	for (int i = 1;i <= n;++i)
		scanf("%d%d",&p[i],&len[i]);
	cin >> q;
	int l,r;
	while (q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r));
	}
	return 0;
}
