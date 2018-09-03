/*********************************
Date: Sat Aug 25 15:14:48 CST 2018
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
ll w[maxn][35],p[maxn][35];
int f[maxn][35];
int a[maxn];
int n,m,k;
void init()
{
	for (int i = 0;i < n;++i){
		f[i][0] = (i+k)%n;
		w[i][0] = a[(i+k)%n];
		p[i][0] = max(0,a[(i+k)%n]);
	}
	for (int j = 1;1<<j <= m;++j){
		for (int i = 0;i < n;++i){
			f[i][j] = f[f[i][j-1]][j-1];
			w[i][j] = w[i][j-1] + w[f[i][j-1]][j-1];
			p[i][j] = max(p[i][j-1],w[i][j-1]+p[f[i][j-1]][j-1]);
		}
	}
}
ll solve(int x)
{
	ll s = a[x];
	ll ans = max(0,a[x]);
	for (int i = 31;i >= 0;--i){
		if (m>>i & 1){
			ans = max(ans,s+p[x][i]);
			s += w[x][i];
			ans = max(ans,s);
			x = f[x][i];
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	ll s;
	for (int kase = 1;kase <= T;++kase){
		scanf("%d%lld%d%d",&n,&s,&m,&k);
		--m;
		for (int i = 0;i < n;++i) scanf("%d",&a[i]);
		init();
		ll ans = 0;
		for (int i = 0;i < n;++i) ans = max(ans,solve(i));
		ans = s-ans;
		ans = max(0ll,ans);
		printf("Case #%d: %lld\n",kase,ans);
	}
	return 0;
}
