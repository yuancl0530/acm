/*********************************
Date: Thu Apr 26 20:15:31 CST 2018
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
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
struct Node
{
	int from;
	int to;
	Node (int from=0,int to=0):from(from),to(to) {}
};

vector<Node>G[maxn];
int grand[maxn][17],depth[maxn];
int Log[maxn];
int a[maxn],b[maxn],tmp[maxn];
int n,u,v;

void init(int n)
{
	for (int i=1;i<=n;++i){
		G[i].clear();
	}
	CL(depth);
	CL(grand);
}

void dfs(int from=0,int u=1)
{
	if (depth[u]) return ;
	depth[u] = depth[from]+1;
	grand[u][0] = from;
	for (int i=1;depth[u]-(1<<i) > 0; ++i){
		grand[u][i] = grand[grand[u][i-1]][i-1];
	}
	for (int i=0;i<G[u].size();++i){
		dfs(u,G[u][i].to);
	}
}

int lca(int a,int b)
{
	if (depth[a]<depth[b]){
		swap(a,b);
	}

	int t=depth[a]-depth[b];
	for (int i=0;t;t>>=1,++i){
		if (t&1){
			a = grand[a][i];
		}
	}

	if (a==b) return a;

	for (int i=Log[n]+1;i>=0;--i){
		if (grand[a][i]!=grand[b][i]){
			a = grand[a][i];
			b = grand[b][i];
		}
	}
	return grand[a][0];
}

bool check(int d)
{
	int cnt = 0;
	for (int i=0;i<u;++i){
		int k = a[i];
		if (depth[k]<d) continue;
		if (depth[k]==d){
			tmp[cnt++] = k;
			continue;
		}
		int t = depth[k]-d;
		for (int j=0;t;t>>=1,++j){
			if (t&1){
				k = grand[k][j];
			}
		}
		tmp[cnt++] = k;
	}
	if (cnt==0) return false;
	sort(tmp,tmp+cnt);
	cnt = unique(tmp,tmp+cnt)-tmp;

	for (int i=0;i<cnt;++i){
		for (int j=0;j<v;++j){
			if (lca(tmp[i],b[j]) == tmp[i])
				return true;
		}
	}
	return false;
}
int main()
{
	int m;
	for (int i=1;i<=10000;++i){
		Log[i] = Log[i/2]+1;
	}
	while (scanf("%d%d",&n,&m)!=EOF){
		init(n);
		for (int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			G[u].push_back(Node(u,v));
			G[v].push_back(Node(v,u));
		}
		dfs();
		while (m--){
			scanf("%d",&u);
			for (int i=0;i<u;++i){
				scanf("%d",&a[i]);
			}
			scanf("%d",&v);
			for (int i=0;i<v;++i){
				scanf("%d",&b[i]);
			}
			int ans = 0;
			int l=1;
			int r=n+1;
			while (l+1<r) {
				int mid = (l+r)>>1;
				if (check(mid)){
					l = mid;
				}
				else {
					r = mid;
				}
			}
			printf("%d\n",l);
		}
	}

	return 0;
}
