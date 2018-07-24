/*********************************
Date: Thu Mar  8 16:30:51 CST 2018
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
const int maxn = 1e5 + 100;
LL a[maxn],b[maxn],k[maxn];
int x[maxn];
vector<int >G[maxn];
int n;
bool f = 1;
const LL inf=1e18;
void dfs(int pos=1)
{
	for (int i=0;i<G[pos].size();++i){
		int v = G[pos][i];
		dfs(v);
		if (a[v]<0){
			double tmp=(double)k[v]*(double)a[v] ;
			if (tmp<-inf || (double)a[pos]+tmp <-inf){
				f=0;
			}
			a[pos] += k[v]*a[v];
			a[v] = 0;
		}
		else{
			a[pos] += a[v];
			a[v] = 0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%lld",&b[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		a[i] = b[i]-a[i];
	}
	for (int i=2;i<=n;++i){
		scanf("%d%lld",&x[i],&k[i]);
		G[x[i]].push_back(i);
	}
	dfs();
	if (f && a[1]>=0)
		printf("YES\n");
	else{
		printf("NO\n");
	}
	return 0;
}
