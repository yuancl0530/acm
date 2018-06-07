/*********************************
Date: Fri Jun  1 15:42:33 CST 2018
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
int a[maxn];
int cost[maxn][110];
int n,m,k,s;
vector<int> E[maxn];
vector<int> G[110];
int q[maxn];
void bfs(int x)
{
	int l=0;
	int r = 0;
	cost[0][x] = 0;
	for (int i = 0;i < G[x].size();++i){
		q[r++] = G[x][i];
		cost[G[x][i]][x] = 0;
	}
	int u;
	while (l < r){
		u = q[l++];
		for (int i = 0;i < E[u].size();++i){
			int v = E[u][i];
			if (cost[v][x] ==-1 ){
				cost[v][x] = cost[u][x] + 1;
				q[r++] = v;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for (int i = 1;i <= n;++i){
		scanf("%d",&a[i]);
		G[a[i]].push_back(i);
	}
	int u,v;
	while (m--){
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	Cl(cost,-1);
	for (int i = 1;i <= k;++i)
		bfs(i);
	for (int i = 1;i <= n;++i){
		int ans = 0;
		sort(cost[i]+1,cost[i]+1+k);
		for (int j = 1;j <=s ;++j)
			ans += cost[i][j];
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}
