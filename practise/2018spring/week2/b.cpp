/*********************************
Date: Thu Mar 15 17:31:58 CST 2018
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
vector<int >V[maxn];
int a[maxn];
int b[maxn];
bool vs[maxn];
int n,m;
vector<int>ans;
void dfs(int u)
{
	if (vs[u]) return ;
	ans.push_back(u);
	b[u]^=1;
	vs[u] = true;
	for (int i=0;i<V[u].size();++i){
		int v = V[u][i];
		if (vs[v]) continue ;
		dfs(v);
		b[u]^=1;
		ans.push_back(u);
		if (b[v]!=a[v]){
			b[v]^=1;
			ans.push_back(v);
			b[u]^=1;
			ans.push_back(u);
		}
	}
}
bool check()
{
	for (int i=1;i<=n;++i)
		if (a[i] != b[i])
			return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		if (a[i]&1){
			dfs(i);
			if (a[i] != b[i]){
				a[i]^=1;
				ans.pop_back();
			}
			break;
		}
	}
	if (check()){
		printf("%d\n",ans.size());
		for (int i=0;i<ans.size();++i)
			printf("%d ",ans[i]);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
