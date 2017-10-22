/*********************************
Date: Wed Sep 27 09:39:54 CST 2017
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
int a[55][55];
int main()
{
	int T;
	scanf("%d",&T);
	int n,m;
	while (T--){
		CL(a);
		scanf("%d%d",&n,&m);
		LL ans=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				if (a[i][j])
					++ans;
			}
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i][j]>a[i-1][j])
					ans+=a[i][j]-a[i-1][j];
				if (a[i][j]>a[i+1][j])
					ans+=a[i][j]-a[i+1][j];
				if (a[i][j]>a[i][j-1])
					ans+=a[i][j]-a[i][j-1];
				if (a[i][j]>a[i][j+1])
					ans+=a[i][j]-a[i][j+1];
			}
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}
