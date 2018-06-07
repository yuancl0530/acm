/*********************************
Date: Wed May 23 15:49:41 CST 2018
Author: ycl
*********************************/
#include <cstdio>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int fa[maxn],d[maxn];
int find(int x)
{
	if (x == fa[x]) return x;
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	d[x] = (d[x]+d[tmp]) % 3;
	return fa[x];
}
bool link(int x,int y,int dis)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy){
		if ((d[x]-d[y]+3)%3 != dis) return false;
		return true ;
	}
	fa[fx] = fy;
	d[fx] = (d[y]-d[x]+dis+3) % 3;
	return true;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0;i <= n;++i) fa[i] = i;
	int op,x,y;
	int ans = 0;
	while (m--){
		scanf("%d%d%d",&op,&x,&y);
		if (x > n || y > n) ++ans;
		else if (op == 2 && x==y) ++ans;
		else if (!link(x,y,op-1)) ++ ans;
	}
	printf("%d\n",ans);
	return 0;
}
