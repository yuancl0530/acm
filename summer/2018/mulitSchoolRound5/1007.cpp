/*********************************
Date: Mon Aug  6 20:26:05 CST 2018
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
unsigned int x,y,z;
unsigned int fun()
{
	x ^= x<<11;
	x ^= x>>4;
	x ^= x<<5;
	x ^= x>>14;
	unsigned w = x^y^z;
	x = y;
	y = z;
	z = w;
	return w;
}
int Log[maxn];
unsigned int s[maxn][25];
void up(unsigned int &x,unsigned int y)
{
	if (x < y) x = y;
}
int main()
{
	freopen("1007.in","r",stdin);
	freopen("out","w",stdout);
	int n,m,T;
	for (int i = 2;i < maxn;++i) Log[i] = Log[i>>1]+1;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%u%u%u",&n,&m,&x,&y,&z);
		while (m--){
			int l = fun()%n+1;
			int r = fun()%n+1;
			unsigned int v = fun()&((1<<30)-1);
			if (l > r) swap(l,r);
			int t = Log[r-l+1];
			up(s[l][t],v);
			up(s[r-(1<<t)+1][t],v);
		}
		for (int j = Log[n];j > 0;--j){
			for (int i = 1;i+(1<<j)-1 <= n;++i){
				up(s[i][j-1],s[i][j]);
				up(s[i+(1<<(j-1))][j-1],s[i][j]);
				s[i][j] = 0;
			}
		}
		ll ans = 0;
		for (int i = 1;i <= n;++i) {
			ans ^= (ll)s[i][0]*i;
			s[i][0] = 0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
