/*********************************
Date: Wed Jul  4 15:18:51 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Edge
{
	int v;
	int a,b;
	Edge(int v=0,int a=0,int b=0):v(v),a(a),b(b) {}
};
struct Node
{
	ll l;
	int u;
	Node(ll l=0,int u=0):l(l),u(u) {}
	friend bool operator < (Node a,Node b)
	{
		return a.l > b.l;
	}
};
ll dis[maxn];
int n;
int a[maxn],b[maxn];
vector<Edge>G[maxn];
bool vs[maxn];
ll f2[100];
int solve()
{
	priority_queue<Node>Q;
	Q.push(Node(1,1));
	dis[1] = 1;
	while (!Q.empty()){
		int u = Q.top().u;
		ll l = Q.top().l;
		Q.pop();
		if (vs[u]) continue;
		vs[u] = true;
		//cout<<u<<endl;
		for (int i = 0;i < G[u].size();++i){
			int a = G[u][i].a;
			int b = G[u][i].b;
			int v = G[u][i].v;
			if (vs[v]) continue;
			if ( (double)a/l+1.0 < f2[b]) continue;
			if (dis[v] == -1 || dis[u]+a < dis[v]) {
				dis[v]  = dis[u] + a;
				Q.push(Node(dis[v],v));
			}
		}
	}
	if (dis[n] == -1) return -1;
	return log2(dis[n]);
}
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int main()
{
	int T,m,a,b;
	f2[0] = 1;
	for (int i = 1;i <= 61;++i)
		f2[i] = f2[i-1]*2;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		int u,v;
		for (int i = 0;i <= n; ++i) {
			G[i].clear();
			dis[i] = -1;
			vs[i] = 0;
		}
		while (m--) {
			u = read();
			v = read();
			a = read();
			b = read();
			G[u].push_back(Edge(v,a,b));
		}
		int ans;
		ans = solve();
		printf("%d\n",ans);
	}
	return 0;
}
