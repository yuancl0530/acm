/*********************************
Date: Sat Sep  9 14:51:52 CST 2017
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
const int maxn = 1e6 + 100;
struct Node
{
	int u;
	LL dis;
	Node (int _u=0,int d=0)
	{
		u=_u;
		dis=d;
	}
	friend bool operator <(Node a,Node b)
	{
		return a.dis<b.dis;
	}
}node[maxn];
struct Edge
{
	int u;
	int v;
	int s;
	Edge(int _u=0,int _v=0,int _s=0)
	{
		u=_u;
		v=_v;
		s=_s;
	}
};
vector<Edge>V[maxn];
int n,m;
int deg[maxn];
priority_queue<Node>Q;
int ans=0;
void dij()
{
	while (!Q.empty()) Q.pop();
	for (int i=1;i<=n;i++)
		if (deg[i]==0)
			Q.push(node[i]);
	while (!Q.empty()){
		Node p=Q.top();
		Q.pop();
		int u=p.u;
		int d=p.dis;
		for (int i=0;i<V[u].size();++i){
			int v=V[u][i].v;
			int s=V[u][i].s;
			if (d+s>node[v].dis){
				node[v].dis=d+s;
				Q.push(node[v]);
				ans=max(ans,d+s);
			}
		}
	}
}
void Init()
{
	CL(node);
	ans=0;
	CL(deg);
	for (int i=1;i<=n;i++){
		V[i].clear();
		node[i].u=i;
		node[i].dis=0;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		Init();
		int u,v,s;
		for (int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&s);
			V[u].push_back(Edge(u,v,s));
			deg[v]++;
		}
		dij();
		cout<<ans<<endl;
	}


	return 0;
}
