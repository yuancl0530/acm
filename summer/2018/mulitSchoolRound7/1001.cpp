/*********************************
Date: Mon Aug 13 13:37:44 CST 2018
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
const int maxn = 1e5 + 100;
struct Edge
{
	int v;
	int c;
	Edge(int v=0,int c=1):v(v),c(c){}
};
struct Node
{
	int u,d,c;
	Node (int u=0,int d=1,int c=0): u(u),d(d),c(c){}
	friend bool operator < (Node a,Node b)
	{
		return a.d > b.d;
	}
};
vector<Edge>G[maxn];
int dis[maxn],n;
set<int> vs[maxn];
void dijkstra(int u = 1)
{
	for (int i = 0;i <= n;++i){
		vs[i].clear();
		dis[i] = -1;
	}
	dis[u] = 0;
	priority_queue<Node> Q;
	for (int i = 0;i < G[u].size();++i){
		int v = G[u][i].v;
		int c = G[u][i].c;
		dis[v] = 1;
		Q.push(Node(v,1,c));
	}
	while (!Q.empty()){
		int u = Q.top().u;
		int d = Q.top().d;
		int c = Q.top().c;
		Q.pop();
		if (vs[u].count(c)) continue;
		vs[u].insert(c);
		for (int i = 0;i < G[u].size();++i){
			int v = G[u][i].v;
			int c1 = G[u][i].c;
			int dist = d + (c != c1);
			if (dis[v] == -1 || dist <= dis[v]){
				dis[v] = dist;
				Q.push(Node(v,dist,c1));
			}
		}
	}
}
int main()
{
	int m;
	int u,v,c;
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i = 0;i <= n;++i) G[i].clear();
		for (int i = 1;i <= m;++i){
			scanf("%d%d%d",&u,&v,&c);
			G[u].push_back(Edge(v,c));
			G[v].push_back(Edge(u,c));
		}
		dijkstra();
		printf("%d\n",dis[n]);
	}
	return 0;
}
