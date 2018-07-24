#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int f[maxn],a[maxn],t[maxn];
bool b[maxn];
ll wa[maxn][20];
int ti[maxn][20],fa[maxn][20];
int n;
vector<int> G[maxn];
void dfs(int u = 1)
{
	if (b[u]) t[u] =  0;
	for (int i = 0;i < G[u].size();++i){
		int v = G[u][i];
		dfs(v);
		if (t[u]) t[u] = min(t[u],t[v]+1);
	}	
}
void init()
{
	fa[1][0] = 0;
	ti[1][0] = n;
	for (int i = 1;i <= n;++i){
		fa[i][0] = f[i];
		wa[i][0] = a[i];
		ti[i][0] = min(t[i],t[f[i]]);
	}
	for (int j = 1;j < 18;++j){
		for (int i = 1;i <= n;++i){
			fa[i][j] = fa[fa[i][j-1]][j-1];
			wa[i][j] = wa[i][j-1] + wa[fa[i][j-1]][j-1];
			ti[i][j] = min(ti[i][j-1],ti[fa[i][j-1]][j-1]);
		}
	}
}
int query(int p,ll lim)
{
	int ans = t[p];
	ll wig = 0;
	for (int i = 17;i >= 0;--i){
		if (wig + wa[p][i] > lim) continue;
		//if (!fa[p][i]) continue;
		wig += wa[p][i];
		ans = min(ans,ti[p][i]);
		p = fa[p][i];
	}
	return ans==n? -1:ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	int m,q,tt;
	while (T--){
		scanf("%d%d%d",&n,&m,&q);
		for (int i = 0;i <= n;++i){
			b[i] = false;
			t[i] = n;
			G[i].clear();
		}
		for (int i = 2;i <= n;++i){
			scanf("%d",&f[i]);
			G[f[i]].push_back(i);
		}
		for (int i = 2;i <= n;++i)
			scanf("%d",&a[i]);
		for (int i = 0;i < m;++i){
			scanf("%d",&tt);
			b[tt] =  true;
		}
		dfs();
		init();
		int p,lim;
		while (q--){
			scanf("%d%d",&p,&lim);
			printf("%d\n",query(p,lim));
		}
	}
	return 0;
}
