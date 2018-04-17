/*********************************
Date: Wed Apr 11 14:16:08 CST 2018
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
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
vector<int>G[maxn];
int V[maxn],ans[maxn],p[maxn];
bool vs[maxn];
int n;
LL gcd(LL a,LL b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
void dfs(int u,int pos)
{
	for (int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if (!vs[v]){
			vs[v]=true;
			if (gcd(V[pos],p[v])==1){
				dfs(v,pos);
				if (gcd(V[pos],V[v])==1){
					ans[pos]++;
				}
			}
			vs[v]=false;
		}
	}
}
void solve(int u=1)
{
	vs[u]=true;
	for (int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if (!vs[v]){
			p[u]=gcd(p[u],p[v]);
			solve(v);
		}
	}
	dfs(u,u);
	vs[u]=false;
}
int main()
{
	int kase=0;
	while (scanf("%d",&n)!=EOF){
		CL(ans);
		for (int i=1;i<=n;++i){
			G[i].clear();
		}
		int u,v;
		for (int i=1;i<n;++i){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for (int i=1;i<=n;++i){
			scanf("%d",&V[i]);
			p[i]=V[i];
		}
		solve();
		#ifdef DEBUG
		for (int i=1;i<=n;++i){
			printf("%d ",p[i]);
		}
		printf("\n");
		#endif
		printf("Case #%d: ",++kase);
		for (int i=1;i<=n;++i){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
