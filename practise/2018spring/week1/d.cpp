/*********************************
Date: Mon Mar  5 19:55:14 CST 2018
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
const int maxn = 500 + 100;
int G[maxn][maxn];
int n,m,k,q;
bool check(int t)
{





	return 0;
}
int main()
{
	Cl(G,0x3f);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	int x,y,t;
	int l = -1;
	int r = 0;
	for (int i = 0;i<q;++i){
		scanf("%d%d%d",&x,&y,&t);
		G[x][y] = t;
		r = max(r,t);
	}
	int mid;
	while (l+1<r){
		mid = (l+r)>>1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (check(r))
		printf("%d\n",r);
	else
		printf("-1\n");
	return 0;
}
