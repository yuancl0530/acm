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
const int maxn = 1e3 + 100;
int dfn[maxn];//点i被访问的次序，时间戳
int low[maxn];//点i可回溯到的在栈中最早的节点
int belong[maxn];
bool inStack[maxn];//点i是否在栈中
int Index;//节点被访问次序的编号
vector<int>edge[maxn];//边
vector<int>edge2[maxn];//DAG图的边
stack<int>S;//栈
int cnt=0;//强连通分量的总数/DAG图中点的个数
int n;//节点数
int m;//边数
void init()//初始化
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
			}
		}
	}
}
int main()
{



	return 0;
}
