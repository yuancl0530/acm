/*********************************
Date: Sat Sep  1 15:36:21 CST 2018
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
const int maxn = 1e5 + 100;
int a[maxn][110],w[maxn][110];
int lm[maxn],rm[maxn];
int s[maxn];
int n,m,k;
ll solve()
{
	ll ans= 0;
	for (int i = 1;i <= n;++i){
		int top = -1;
		w[i][0] = -1;
		s[++top] = 0;
		for (int j = 1;j <= m;++j){
			while (top >=0 && w[i][s[top]] >= w[i][j]) --top;
			lm[j] = s[top];
			s[++top] = j;
		}
		top = -1;
		w[i][m+1] = -1;
		s[++top] = m+1;
		for (int j = m;j >= 1;--j){
			while (top >=0 && w[i][s[top]] > w[i][j]) --top;
			rm[j] = s[top];
			s[++top] = j;
		}
		for (int j = 1;j <= m;++j){
			ans += (ll)w[i][j] * (j-lm[j])* (rm[j]-j);
		}
	}
	return ans;
}
int main()
{
	int T,x,y;
	scanf("%d",&T);
	for (int kase=1;kase <= T;++kase){
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n;++i)
			for (int j = 1;j <= m;++j)
				a[i][j] =w [i][j] = 0;
		for (int i = 0;i < k;++i){
			scanf("%d%d",&x,&y);
			a[x][y]  = 1;
		}
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= m;++j)
				w[i][j] = a[i][j]? 0:w[i-1][j]+1;
		}
		printf("Case #%d: %lld\n",kase,solve());
	}
	return 0;
}
