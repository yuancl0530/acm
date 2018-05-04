/*********************************
Date: Sun Apr 29 11:45:35 CST 2018
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
const int maxn = 1e6 + 100;
ll cnt[2];//depth  00 
vector<int>G[maxn];
bool vs[maxn];
void dfs(int u,int d=1)
{
	if (vs[u]) return ;
	vs[u] = true;
	++cnt[d&1];
	for (int i=0;i<G[u].size();++i){
		dfs(G[u][i]);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	while (T--){
		scanf("%d",&n);
		CL(vs);
		for (int i=0;i<=n;++i) G[i].clear();
		int u,v;
		for (int i=0;i<n-1;++i){
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1);
		ll ans = 0;
		int d = n&1;
		for (int i=1;i<=n;++i){
			if (d==0) {
				ans += cnt[0]*cnt[0];
				ans += cnt[1]*cnt[1];
			}
			else {
				ans += 2*cnt[0]*cnt[1];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
