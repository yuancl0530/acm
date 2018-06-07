/*********************************
Date: Thu Feb  1 13:54:04 CST 2018
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
int deg[maxn];
int dp[maxn][30];
char value[maxn];
int n,m;
int ID(int i)
{
	return value[i]-'a';
}
vector<int> Edge[maxn];
int solve()
{
	int cnt=0;
	queue<int>Q;
	for (int i=1;i<=n;++i)
		if (!deg[i]){
			Q.push(i);
			++cnt;
			++dp[i][ID(i)];
		}
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int i=0;i<Edge[u].size();++i){
			int v = Edge[u][i];
			--deg[v];
			for (int j=0;j<26;++j){
				if (j!= ID(v))
					dp[v][j] = max(dp[u][j],dp[v][j]);
				else
					dp[v][j] = max(dp[u][j]+1,dp[v][j]);
					
			}
			if (!deg[v]){
				++cnt;
				Q.push(v);
			}
		}
	}
	if (cnt != n)
		return -1;
	int ret = -1;
	for (int i=1;i<=n;++i){
		for (int j=0;j<26;++j)
			ret = max(ret,dp[i][j]);
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",value+1);
	int u,v;
	for (int i=0;i<m;++i){
		scanf("%d%d",&u,&v);
		Edge[u].push_back(v);
		deg[v]++;
	}
	int ans = solve();
	printf("%d\n",ans);
	return 0;
}
