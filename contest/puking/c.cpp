/*********************************
Date: Sat Sep 23 14:51:40 CST 2017
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
const int maxn = 3e2 + 100;
int a[maxn][maxn];
int sum[maxn][maxn];
int mi[maxn][maxn];
int main()
{
	int n,m,k;
	while (scanf("%d%d%d",&n,&m,&k)!=EOF){
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j){
				scanf("%d",&a[i][j]);
				mi[i][j]=INF;
				sum[i][j]=sum[i][j-1]+sum[i-1][j]+a[i][j]-sum[i-1][j-1];
			}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
				mi[i][j] = min(a[i][j],min(mi[i][j-1],mi[i-1][j]));

			
	}
	return 0;
}
