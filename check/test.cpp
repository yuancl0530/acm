/*********************************
Date: Fri May  4 16:50:26 CST 2018
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	int op;
	int x,y,v;
	while (m--){
		scanf("%d",&op);
		if (op){
			scanf("%d%d",&x,&y);
			int ans = 0;;
			for (int i=x;i<=y;++i){
				ans = max(ans,a[i]);
			}
			printf("%d\n",ans);
		}
		else{
			scanf("%d%d%d",&x,&y,&v);
			for (int i=x;i<=y;++i){
				a[i] += v;
			}
		}
	}
	return 0;
}
