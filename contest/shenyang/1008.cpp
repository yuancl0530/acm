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
struct Edge
{
	int u,v;
	int s;
	Edge(int u=0,int v=0,int s=0)
	{
		this->u=u;
		this->v=v;
		this->s=s;
	}
};
struct Node
{
	int m;
	int n;
	int p;
	Node ()
	{
		m=INF;
		p=n=0;
	}
}node[maxn];
vector<Edge>edge[maxn];
int ans;
bool vs[maxn];
void dfs(int u)
{
	vs[u]=true;
	for (int i=0;i<edge[u].size();++i){
		int v=edge[u][i].v;
		if (vs[v])continue;
		int s=edge[u][i].s;
		dfs(v);
		node[u].m=min(node[u].m,min(node[v].p,node[v].m)+s);
		node[u].n=max(node[u].n,max(node[v].p,node[v].n)-s);
	}
	int tmp=max(node[u].p-node[u].m,node[u].n-node[u].p);
	ans=max(ans,tmp);
	ans=max(ans,node[u].n-node[u].m);
	vs[u]=false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		CL(vs);
		ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;++i){
			edge[i].clear();
			node[i].m=INF;
			node[i].n=0;
			node[i].p=0;
		}
		for (int i=1;i<=n;i++){
			scanf("%d",&node[i].p);
		}
		int u,v,s;
		for (int i=1;i<n;i++){
			scanf("%d%d%d",&u,&v,&s);
			edge[u].push_back(Edge(u,v,s));
			edge[v].push_back(Edge(v,u,s));
		}
		dfs(1);
		ans=max(ans,0);
		printf("%d\n",ans);
	}
	return 0;
}
