/*********************************
Date: Fri Jul 27 15:37:21 CST 2018
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
const int maxn = 100;
char G[maxn][maxn];
bool vs[maxn][maxn];
int n,m;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
bool ans = 0;
void dfs(int x,int y,int d = -1)
{
	if (ans) return ;
	vs[x][y] = 1;
	for (int i = 0;i < 4;++i){
		if (d != -1 && (d+2)%4 == i) continue ;
		int u = x + dx[i];
		int v = y + dy[i];
		if (u < 0 || u>=n || v <0 || v>=m) continue;
		if (G[u][v] != G[x][y]) continue;
		//cout<<x<<" "<<y<<" "<<u<<" "<<v<<" "<<d<<endl;
		if (vs[u][v]){
			ans = 1;
			return ;
		}
		vs[u][v] = true;
		dfs(u,v,i);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 0;i < n ;++i)
		scanf("%s",G[i]);
	for (int i = 0;i < n  && !ans;++i){
		for (int j = 0;j < m && !ans ;++j){
			if (!vs[i][j])
				dfs(i,j);
		}
	}
	printf("%s\n",ans? "Yes":"No");
	return 0;
}
