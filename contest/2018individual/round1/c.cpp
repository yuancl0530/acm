/*********************************
Date: Fri Mar  9 13:29:05 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
LL pos[maxn];
int vs[maxn];
int deg[maxn];
struct Node
{
	int r,d;
	Node(int r=0,int d=0):r(r),d(d)
	{
		
	}
};
vector<Node> G[maxn],G2[maxn];
int ans=1;
void dfs(int );
void dfs2(int u)
{
	for (int i=0;i<G2[u].size();++i){
		int v = G2[u][i].r;
		if (!vs[v]){
			vs[v]=1;
			pos[v] = pos[u]-G2[u][i].d;
			dfs(v);
		}
		else{
			if (pos[v] != pos[u]-G2[u][i].d)
				ans=0;
		}
	}
}
void dfs(int v)
{
	for (int i=0;i<G[v].size();++i){
		int u =G[v][i].r;
		if (!vs[u]){
			vs[u]=1;
			pos[u]=pos[v]+G[v][i].d;
			dfs(u);
		}
		else{
			if (pos[u] != pos[v]+G[v][i].d)
				ans=0;
		}
	}
	dfs2(v);
}
int main()
{
	int n,m,l,r,d;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i){
		scanf("%d%d%d",&l,&r,&d);
		G[l].push_back(Node(r,d));
		G2[r].push_back(Node(l,d));
		++deg[r];
	}
	int cnt=0;
	for (int i=1;i<=n;++i){
		if (!vs[i]){
			vs[i]=1;
			pos[i]=0;
			dfs(i);
		}
		if (!ans) break;
	}
	if (ans)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
