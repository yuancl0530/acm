/*********************************
Date: Thu Apr 26 10:26:01 CST 2018
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
#define inf 0x7fffffff
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e2 + 100;
int g[maxn][maxn];
char s[maxn];
int dis[maxn];
bool vs[maxn];
int n;
int cnt[maxn];
void dijkstra(int u)
{
	dis[0]=0;
	for (int i=0;i<n;++i){
		if (g[u][i]!=0){
			dis[i] = g[u][i];
		}
	}
	vs[u] = true;
	int now;
	for (int k=0;k<n;++k){
		int Min = inf;
		for (int i=0;i<n;++i){
			if (!vs[i] && dis[i]>0 && Min>dis[i]){
				Min = dis[i];
				now = i;
			}
		}
		if (Min==inf) break;
		vs[now] = true;
		for (int i=0;i<n;++i){
			if (g[now][i]==0) continue;
			if (vs[i]) continue;
			if (dis[i]==-1 || dis[i]>dis[now]+g[now][i]){
				dis[i] = dis[now]+g[now][i];
			}
		}
	}
}
int main()
{
	while (scanf("%d",&n)!=EOF){
		Cl(dis,-1);
		CL(cnt);
		for (int i=0;i<n;++i){
			scanf("%s",s);
			for (int j=0;s[j];++j){
				g[i][j] = s[j]-'0';
			}
		}
		CL(vs);
		dijkstra(0);
		ll ans=1;
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j){
				if (i==j)continue;
				if (g[i][j]==0) continue;
				if (dis[j] == dis[i]+g[i][j]){
					++cnt[j];
				}
			}
		}
		for (int i=1;i<n;++i){
			ans = ans*cnt[i]%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
