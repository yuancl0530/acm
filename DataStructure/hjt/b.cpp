/*********************************
Date: Mon Aug  6 09:22:09 CST 2018
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
struct Node
{
	int sum;
	Node *left,*right;
	void init(Node *l,Node *r,int s=0)
	{
		sum = s;
		left = l;
		right = r;
	}
}node[20*maxn],*root[maxn];
int id,n;
bool vs[maxn];
vector<int>G[maxn];
int a[maxn],b[maxn],num[maxn];
int fa[maxn][20],dep[maxn];
Node *modify(int left,int right,int x,Node *f)
{
	if (x<left || x>right) return f;
	Node *p = &node[id++];
	*p = *f;
	++p->sum;
	if (left == right) return p;
	int mid = (left+right)>>1;
	p->left = modify(left,mid,x,f->left);
	p->right = modify(mid+1,right,x,f->right);
	return p;
}
void dfs(int u,Node* f,int d=1)
{
	vs[u] = true;
	dep[u] = d;
	root[u] = modify(1,n,num[u],f);
	for (int i = 0;i < G[u].size();++i){
		int v = G[u][i];
		if (vs[v]) continue;
		fa[v][0] = u;
		dfs(v,root[u],d+1);
	}
}
void build()
{
	root[0] = &node[id++];
	node[0].init(root[0],root[0]);
	dfs(1,root[0]);
}
void initlca()
{
	for (int j = 1;j < 20;++j){
		for (int i = 1;i <= n;++i)
			fa[i][j] = fa[fa[i][j-1]][j-1];
	}
}
int lca(int u,int v)
{
	if (dep[u] > dep[v]) swap(u,v);
	int t = dep[v] - dep[u];
	for (int i = 20;i >= 0;--i){
		if ((t>>i)&1) v = fa[v][i];
	}
	if (u==v) return u;
	for (int i = 19;i >= 0;--i){
		if (fa[u][i] == fa[v][i]) continue;
		u = fa[u][i];
		v = fa[v][i];
	}
	return fa[u][0];
}
int query(int left,int right,int k,Node *u,Node *v,Node *g,Node *p)
{
	if (left == right) return left;
	int sum = u->left->sum + v->left->sum - g->left->sum - p->left->sum;
	int mid = (left+right)>>1;
	if (k<=sum) return query(left,mid,k,u->left,v->left,g->left,p->left);
	return query(mid+1,right,k-sum,u->right,v->right,g->right,p->right);
}
int main()
{
	int m,u,v,k;
	while (scanf("%d%d",&n,&m) != EOF){
		id = 0;
		for (int i = 0;i <= n;++i) {
			vs[i] = 0;
			G[i].clear();
		}
		fa[1][0] = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		b[0] = 0;
		sort(b+1,b+1+n);
		int cnt = unique(b+1,b+1+n) - b;
		for (int i = 1;i <= n;++i) num[i] = lower_bound(b+1,b+cnt,a[i]) - b;
		for (int i = 1;i < n;++i){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		build();
		initlca();
		while (m--){
			scanf("%d%d%d",&u,&v,&k);
			int g = lca(u,v);
			//cout<<u<<" "<<v<<" "<<g<<endl;
			int pos = query(1,n,k,root[u],root[v],root[g],root[fa[g][0]]);
			printf("%d\n",b[pos]);
		}
	}
	return 0;
}
