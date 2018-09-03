/*********************************
Date: Fri Aug 24 13:47:36 CST 2018
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
int a[maxn],b[maxn];
int p[maxn],n;
bool check(int v)
{
	static int t = 0;
	++t;
	if (t&1)
	for (int i = 2;i <= n;++i){
		if (v <= a[i] && a[i] % v==0) continue;
		if (v <= b[i] && b[i] % v==0) continue;
		return false;
	}
	else
	for (int i = n;i >= 2 ;--i){
		if (v <= a[i] && a[i] % v==0) continue;
		if (v <= b[i] && b[i] % v==0) continue;
		return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;++i)
		scanf("%d%d",&a[i],&b[i]);
	int cnt = 0;
	for (int i = 1;(ll)i*i <= (ll)a[1];++i){
		if (a[1]%i == 0) {
			if (i > 1) p[cnt++] = i;
			if (a[1] != i) p[cnt++] = a[1]/i;
		}
	}
	for (int i = 1;(ll)i*i <= (ll)b[1];++i){
		if (b[1]%i == 0) {
			if (i > 1) p[cnt++] = i;
			if (b[1] != i) p[cnt++] = b[1]/i;
		}
	}
	sort(p,p+cnt);
	cnt = unique(p,p+cnt) - p;
	int ans = -1;
	for (int i = 0;i < cnt;++i)
		if (check(p[i])) {ans = p[i];break;}
	printf("%d\n",ans);
	return 0;
}
