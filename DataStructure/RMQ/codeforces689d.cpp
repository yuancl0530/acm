/*********************************
Date: Fri Aug 10 19:44:24 CST 2018
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
int n;
int s_max[maxn][20],s_min[maxn][20],Log[maxn];
int a[maxn],b[maxn];
void init()
{
	for (int i = 1;i <= n;++i){
		s_max[i][0] = a[i];
		s_min[i][0] = b[i];
	}
	for (int j = 1;(1<<j) <= n;++j){
		for (int i = 1;i +(1<<j)-1 <= n;++i){
			s_max[i][j] = max(s_max[i][j-1],s_max[i+(1<<(j-1))][j-1]);
			s_min[i][j] = min(s_min[i][j-1],s_min[i+(1<<(j-1))][j-1]);
		}
	}
}
int f_min(int l,int r)
{
	int t = Log[r-l+1];
	return min(s_min[l][t],s_min[r-(1<<t)+1][t]);
}
int f_max(int l,int r)
{
	int t = Log[r-l+1];
	return max(s_max[l][t],s_max[r-(1<<t)+1][t]);
}
int b_min(int x)
{
	int l = x - 1;
	int r = n;
	while (l+1 < r){
		int mid = (l+r)>>1;
		if (f_max(x,mid) >= f_min(x,mid))
			r = mid;
		else
			l = mid;
	}
	if (f_max(x,r) == f_min(x,r)) return r;
	return 0;
}
int b_max(int x)
{
	int l = x;
	int r = n+1;
	while (l+1 < r){
		int mid = (l+r)>>1;
		if (f_max(x,mid) <= f_min(x,mid))
			l = mid;
		else
			r = mid;
	}
	if (f_max(x,l) == f_min(x,l)) return l;
	return 0;
}
int main()
{
	for (int i = 2;i < maxn;++i) Log[i] = Log[i>>1] + 1;
	scanf("%d",&n);
	for (int i = 1;i <= n;++i)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;++i)
		scanf("%d",&b[i]);
	init();
	ll ans = 0;
	for (int i = 1;i <= n;++i){
		int l = b_min(i);
		int r = b_max(i);
		if (l && r) ans += r-l+1;
	}
	printf("%lld\n",ans);
	return 0;
}
