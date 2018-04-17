/*********************************
Date: Wed Aug 23 14:28:59 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 100;
int dfn[maxn];
int low[maxn];
int belong[maxn];
bool inStack[maxn];
int Index;
vector<int>edge[maxn];
vector<int>edge2[maxn];
stack<int>S;
int cnt=0;
int n;
int m;
int value[maxn];
int deg[maxn];
void init()
{
	Index=cnt=0;
	CL(dfn);
	CL(low);
	CL(inStack);
	CL(belong);
	for (int i=0;i<maxn;i++){edge2[i].clear(); edge[i].clear();}
}
void tarjan(int u)
{
	dfn[u]=low[u]=++Index;
	S.push(u);
	inStack[u]=true;
	for (int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (inStack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if (dfn[u]==low[u]){
		int t;
		++cnt;
		do{
			t=S.top();
			belong[t]=cnt;
			++value[cnt];
			S.pop();
			inStack[t]=false;
		}while (t!=u);
	}
}
void buildDAG()
{
	for (int i=1;i<=n;i++){
		for (int j=0;j<edge[i].size();j++){
			int v=edge[i][j];
			if (belong[i]!=belong[v]){
				edge2[belong[i]].push_back(belong[v]);
				++deg[belong[v]];
			}
		}
	}
}
LL dfs(int u)
{
	LL t=0;
	for (int i=0;i<edge2[u].size();++i){
		int v=edge2[u][i];
		t=max(t,dfs(v));
	}
	return value[u]+t;
}
int main()
{
	init();
	scanf("%d%d",&n,&m);
	int u,v;
	for (int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
	}
	for (int i=1;i<=n;++i){
		if (!dfn[i]){
			tarjan(i);
		}
	}
	buildDAG();

	LL ans=0;
	for (int i=1;i<=cnt;++i){
		if (!deg[i]){
			ans=max(ans,dfs(i));
		}
	}
	printf("%lld\n",ans);
	return 0;
}
