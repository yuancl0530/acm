/*********************************
Date: Tue Jul  3 23:36:31 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn =  100;
int a[maxn],b[maxn];
int c[maxn];
int solve(int v)
{
	for (int i = 0;i < 32;++i)
		b[i] = a[i];
	for (int i=0;i < 32;++i){
		c[i] = (v>>i) & 1;
	}
	int ans = 0;
	for (int i = 31;i >= 1;--i){
		if (!c[i]) continue;
		if (b[i]>=c[i]) {
			ans += c[i];
		}
		else  {
			ans += b[i];
			c[i-1] += 2*(c[i]-b[i]);
		}
	}
	if (c[0] <= b[0]) return ans+c[0];
	return -1;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i = 0;i < n;++i){
		int t;
		scanf("%d",&t);
		for (int j = 0;j < 32;++j)
			if ((t>>j) & 1) {
				++a[j];
				break;
			}
	}
	while (q--){
		int t;
		scanf("%d",&t);
		printf("%d\n",solve(t));
	}
	return 0;
}
