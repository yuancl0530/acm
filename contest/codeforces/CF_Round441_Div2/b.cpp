/*********************************
Date: Mon Oct 16 19:25:54 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
int cnt[maxn];
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	int t=-1;
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		cnt[a[i]%m]++;
		if (cnt[a[i]%m]==k){
			t=a[i]%m;
		}
	}
	if (t==-1)
			printf("No\n");
	else{
		int tt=0;
		printf("Yes\n");
		for (int i=0;i<n;++i)
			if (a[i]%m==t){
				printf("%d ",a[i]);
				++tt;
				if (tt==k) break;
			}
			printf("\n");
	}
	return 0;
}
