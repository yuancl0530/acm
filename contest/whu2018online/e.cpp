/*********************************
Date: Sun Apr 15 16:35:18 CST 2018
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
const int maxn = 5e3 + 100;
LL n;
int b[maxn];
int G[maxn][maxn];
LL dis[maxn];
bool vs[maxn];
void dijkstar(int n)
{
	dis[0]=0;
	for (int i=0;i<n;++i){
		if (G[0][i] >=0 )dis[i]=G[0][i];
	}
	vs[0]=1;
	LL inf=1e15;
	int now;
	for (;;){
		LL Min=inf;
		now=-1;
		for (int j=0;j<n;++j){
			if (!vs[j] && dis[j]<Min){
				Min=dis[j];
				now=j;
			}
		}
		if (now==-1) break;
		vs[now]=1;
		for (int j=0;j<n;++j){
			if (!vs[j]&&G[now][j]>=0&& dis[now]+G[now][j]<dis[j]){
				dis[j]=dis[now]+G[now][j];
			}
		}
	}
}
int main()
{
	int m;
	scanf("%lld%d",&n,&m);
	for (int i=0;i<m;++i){
		scanf("%d",&b[i]);
	}
	int Mod=b[0];
	LL inf=1e15;
	for (int i=0;i<Mod;++i){
		dis[i]=inf;
	}
	for (int i=0;i<=5000;++i){
		for (int j=0;j<=5000;++j){
			G[i][j]=-1;
		}
		G[i][i]=0;
	}
	for (int i=0;i<Mod;++i){
		for (int j=0;j<m;++j){
			int to=(i+b[j])%Mod;
			G[i][to]=G[i][j]==-1? b[j]:min(G[i][to],b[j]);
		}
	}
	dijkstar(Mod);
	int ans;
	int val=n%Mod;
	for (int i=0;i<mod;++i){
		int tmp=(val-i+Mod)%Mod;
		if (dis[tmp]!=inf && dis[tmp]<=n-i){
			ans=i;
			break;
		}
		tmp=(val+i)%Mod;
		if (dis[tmp]==inf) continue;
		if (dis[tmp]<=n+i){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
