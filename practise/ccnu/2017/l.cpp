/*********************************
Date: Wed Apr 25 13:36:58 CST 2018
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
int a[maxn];
int main()
{
	int kase=0;
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<m;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+m);
		int ans = n-(unique(a,a+m)-a);
		if (ans){
			printf("CASE #%d: %d\n", ++kase,ans);
		}
		else{
			printf("CASE #%d: Congratulations!\n",++kase);
		}
	}
	return 0;
}
