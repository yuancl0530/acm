/*********************************
Date: Sun Oct 29 13:27:29 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 100 + 100;
vector<int>edge[maxn];
bool e[maxn][maxn];
int S[maxn];
int cnt=0;
int ans=0;
int deg[maxn];
void Init()
{
	CL(e);
	CL(deg);
	for (int i=0;i<=100;++i)
		edge[i].clear();
}

bool check(int v)
{
	for (int i=0;i<cnt;++i)
		if (!e[v][S[i]])
			return false;
	return true;
}
void dfs(int u,int s)
{
	if (cnt==s){
		++ans;
		return ;
	}
	for (int i=0;i<edge[u].size();++i){
		int v=edge[u][i];
		if (check(v) && deg[v]>=s-1){
			S[cnt++]=v;
			dfs(v,s);
			--cnt;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m,s;
		Init();
		scanf("%d%d%d",&n,&m,&s);
		int v,u;
		for (int i=0;i<m;++i){
			scanf("%d%d",&u,&v);
			if (u>v) swap(u,v);
			edge[u].push_back(v);
			e[u][v]=true;
			e[v][u]=true;
			++deg[u];
			++deg[v];
		}
		ans=0;
		for (int i=1;i<=n;++i){
			cnt=0;
			S[cnt++]=i;
			dfs(i,s);
		}
		printf ("%d\n",ans);
	}
	return 0;
}
