/*********************************
Date: Sat May 26 13:48:47 CST 2018
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
vector<int>G[maxn];
bool vs[maxn];
bool s[maxn];
int ans = 0;
void dfs(int u = 1)
{
	vs[u] = true;
	int t  =0;
	int t2 = 0;
	for (int i = 0 ;i < G[u].size();++i){
		int v = G[u][i];
		if (vs[v]) continue;
		++t2;
		dfs(v);
		if (s[v]) ++t;
	}
	if ((t2-t)&1){
		s[u] = true;
	}
	ans += t;
	vs[u] = false;
}
int main()
{
	int n;
	int u,v;
	scanf("%d",&n);
	for (int i = 1;i < n;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs();
	if (!s[1]) ans = -1;
	printf("%d\n",ans);
	return 0;
}
