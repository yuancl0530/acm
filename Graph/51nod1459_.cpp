/*********************************
Date: Wed Nov  1 21:08:11 CST 2017
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
const int maxn = 1e6+ 100;
struct Node
{
	int u;
	int dis;
	int score;
	Node(int u=0,int dis=0,int score=0):u(u),dis(dis),score(score){}
	friend bool operator < (Node a,Node b)
	{
		return a.dis>b.dis;
	}
};
struct Edge
{
	int v;
	int cost;
	Edge(int v=0,int cost=0):v(v),cost(cost){}
};
priority_queue<Node>Q;
vector<Edge>edge[maxn];
int n,m,start,end;
int score[maxn],s[maxn],dis[maxn];
void Dij()
{
	CL(score);
	Cl(dis,0x7f);
	dis[start]=0;
	score[start]=s[start];
	while (!Q.empty())  Q.pop();
	Q.push(Node(start,0));
	for (;!Q.empty();){
		int u=Q.top().u;
		Q.pop();
		for (int i=0;i<edge[u].size();++i){
			int v=edge[u][i].v;
			int c=edge[u][i].cost;
			if (dis[u]+c<dis[v]){
				dis[v]=dis[u]+c;
				score[v]=score[u]+s[v];
				Q.push(Node(v,dis[v]));
			}
			else if (dis[u]+c == dis[v]){
				score[v]=max(score[u]+s[v],score[v]);
				Q.push(Node(v,dis[v]));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&start,&end);
	for (int i=0;i<n;++i) 
		scanf("%d",&s[i]);
	int u,v,c;
	for (int i=0;i<m;++i){
		scanf("%d%d%d",&u,&v,&c);
		edge[u].push_back(Edge(v,c));
		edge[v].push_back(Edge(u,c));
	}
	Dij();
	printf("%d %d\n",dis[end],score[end]);

	return 0;
}
