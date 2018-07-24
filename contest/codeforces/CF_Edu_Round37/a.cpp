/*********************************
Date: Fri Feb  2 22:35:08 CST 2018
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
#define INF 500
const int maxn = 200;
int a[maxn];
int dl[maxn],dr[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while (t--){
		int n,k;
		scanf("%d%d",&n,&k);
		int p;
		CL(a);
		for (int i=0;i<k;++i){
			scanf("%d",&p);
			a[p] = 1;
		}
		CL(dl);
		CL(dr);
		int j=INF;
		for (int i=1;i<=n;++i){
			if (a[i] == 1)
				j = 1;
			dl[i] = j;
			j++;
		}
		j = INF;
		for (int i=n;i>=1;--i){
			if (a[i] == 1)
				j= 1;
			dr[i] = j;
			++j;
		}
		int ans = -1;
		for (int i=1;i<=n;++i){
			ans = max(ans,min(dl[i],dr[i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
