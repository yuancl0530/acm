/*********************************
Date: Fri Mar 16 14:22:54 CST 2018
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
int to[maxn];
int n;
bool vs[maxn];
int num[maxn];
int dfs(int u)
{
	if (vs[u])
		return num[u];
	vs[u]=1;
	return num[u] = dfs(to[u])+1;
}
int main()
{
	int u,v;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&to[i]);
	}
	for (int i=1;i<=n;++i){
		if (!vs[i]){
			dfs(i);
		}
	}
	int ans = 0;
	for (int i=1;i<=n;++i)
		ans = max(ans,num[i]);
	printf("%d\n",ans);
	return 0;
}
