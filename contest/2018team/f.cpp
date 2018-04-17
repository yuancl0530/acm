/*********************************
Date: Fri Apr 13 17:11:20 CST 2018
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
const int maxn = 1e6 + 100;
vector<int>G[maxn];
int deep[maxn];
int ans=1;
bool vs[maxn];
int ch[maxn];
vector<int>V[maxn];
void dfs(int u,int d=1)
{	
	if (!ans) return ;
	vs[u]=1;
	deep[u]=max(deep[u],d);
	for (int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if (vs[v]){
			ans=0;
			return ;
		}
		dfs(v,d+1);
	}
	vs[u]=0;
}
int build(int u)
{
	if (!ans) return 0;
	vs[u]=1;
	for (int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if (vs[v]){
			ans=0;
			return 0;
		}
		if (deep[u]+1==deep[v]){
			ch[u]+=build(v);
			V[u].push_back(v);
		}
	}
	vs[u]=0;
	return ch[u]+1;
}

int main()
{
	int n;
	scanf("%d",&n);
	int root=0;
	int v=0;
	for (int i=1;i<=n;++i){
		int t,a;
		scanf("%d",&t);
		for (int j=0;j<t;++j){
			scanf("%d",&a);
			G[i].push_back(a);
		}
		if (v<t){
			root=i;
			v=t;
		}
	}
	dfs(root);
	if (!ans || build(root)!=n){
		ans=0;
	}

	for (int i=1;ans&&i<=n;++i){
		if (ch[i] != G[i].size()){
			ans=0;
			break;
		}
	}
	if (ans){
		printf("YES\n");
		for (int i=1;i<=n;++i){
			for (int j=0;j<V[i].size();++j){
				printf("%d %d\n",i,V[i][j]);
			}
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}
