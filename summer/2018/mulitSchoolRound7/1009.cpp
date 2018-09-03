/*********************************
Date: Mon Aug 13 12:22:32 CST 2018
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
int n,fa[maxn][20],t[maxn];
int d[maxn];
int getd(int x)
{
	if (x == 1 || d[x]) return d[x];
	return d[x] = getd(fa[x][0]) + 1;
}
int getg(int x,int v)
{
	for (int i = 19;i >= 0;--i){
		if ((v>>i&1) == 0) continue;
		x = fa[x][i];
	}
	return x;
}
int ti[maxn];

int getti(int x)
{
	if (!x) return 0;
	if (ti[x] != -1) return ti[x]+1;
	ti[x] = getti(getg(x,t[x]));
	return ti[x] + 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		fa[1][0] = 0;
		d[1] = 0;
		for (int i = 0;i <= n;++i) ti[i] = -1;
		ti[0] = 0;

		for (int i = 2;i <= n;++i)
			scanf("%d",&fa[i][0]);
		for (int i = 1;i <= n;++i)
			scanf("%d",&t[i]);

		for (int i = 2;i <= n;++i)
			getd(i);

		for (int j = 1;j < 20;++j){
			for (int i = 1;i <= n;++i){
				fa[i][j] = fa[fa[i][j-1]][j-1];
			}
		}

		int m,op,x,y;
		scanf("%d",&m);
		while (m--){
			scanf("%d",&op);
			if (op == 1){
				scanf("%d",&x);
				printf("%d\n",getti(x));
			}
			else{
				scanf("%d%d",&x,&y);
				t[x] = y;
				ti[x] = -1;
			}
		}
	}
	return 0;
}
