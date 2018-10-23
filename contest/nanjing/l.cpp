/*********************************
Date: Mon Sep  3 20:35:30 CST 2018
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
int n,m,k;
struct Edge
{
	int v,w;
	Edge(int v=0,int w=0):v(v), w(w) {}
};
struct Node
{
	ll dis;
	int u,t;
	Node(ll dis=0,int u=0,int t=0):dis(dis),u(u),t(t) {}
	friend bool operator < (const Node &a,const Node &b)
	{
		return a.dis > b.dis;
	}
};
vector<Edge> G[maxn];
ll dis[maxn][15];

ll solve()
{
	Cl(dis,0x3f);
	dis[1][0] = 0;
	priority_queue<Node> Q;
	Q.push(Node(0,1,0));
	while (!Q.empty())
	{
		int u = Q.top().u;
		int t = Q.top().t;
		ll d = Q.top().dis;
		Q.pop();
		for (int i = 0;i < (int)G[u].size();++i){
			int v = G[u][i].v;
			ll w = G[u][i].w;
			if (dis[v][t] > d + w){
				dis[v][t] = d + w;
				Q.push(Node(d+w,v,t));
			}
			int tmp = t+1;
			if (tmp <= k && dis[v][tmp] > d){
				dis[v][tmp] = d;
				Q.push(Node(d,v,tmp));
			}
		}
	}
	return *min_element(dis[n],dis[n]+1+k);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&n,&m,&k);
		for (int i = 1;i <= n;++i) G[i].clear();
		int u,v,w;
		for (int i = 0;i < m;++i){
			scanf("%d%d%d",&u,&v,&w);
			G[u].push_back(Edge(v,w));
		}
		ll ans = solve();
		printf("%lld\n",ans);
	}
	return 0;
}
