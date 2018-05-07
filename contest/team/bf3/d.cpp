/*********************************
Date: Sat May  5 15:46:06 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int u;
	ll d;
	Node (int u=0,ll d=0):u(u),d(d){}
	friend bool operator < (Node a,Node b)
	{
		return a.d > b.d;
	}
};
int n,m;
ll dis[maxn];
int from[maxn];
vector<Node>G[maxn];
void dijkstra(int s=1)
{
	priority_queue<Node>Q;
	Cl(dis,-1);
	Cl(from,-1);
	Q.push(Node(s,0));
	dis[s] = 0;
	while (!Q.empty()){
		int u = Q.top().u;
		Q.pop();
		for (int i=0;i<G[u].size();++i){
			int v = G[u][i].u;
			ll d = G[u][i].d;
			if (d==-1) continue;
			if (dis[v] == -1 || dis[v] > dis[u]+d){
				dis[v] = dis[u]+d;
				from[v] = u;
				Q.push(Node(v,dis[v]));
			}
		}
	}
}
void del()
{
	for (int i=0;i<n;++i){
		for (int j=0;j<G[i].size();++j){
			if (from[G[i][j].u] == i){
				G[i][j].d = -1;
			}
		}
	}
}
vector<int>ans;
int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	ll d;
	for (int i=0;i<m;++i){
		scanf("%d%d%lld",&u,&v,&d);
		G[u].push_back(Node(v,d));
		G[v].push_back(Node(u,d));
	}
	dijkstra();
	del();
	dijkstra();
	int t = 0;
	ans.push_back(t);
	while (t!=-1){
		t = from[t];
		ans.push_back(t);
		if (t==1) break;
	}
	if (t==1){
		printf("%d",(int)ans.size());
		for (int i=0;i<ans.size();++i){
			printf(" %d",ans[i]);
		}
		printf("\n");
	}
	else{
		printf("impossible\n");
	}
	return 0;
}
