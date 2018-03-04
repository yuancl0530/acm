/*********************************
Date: Thu Nov 16 19:49:37 CST 2017
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
int f[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		f[i]=i-1;
	}
	f[a[1]]=min(f[a[1]],1);
	int t=a[1]-1;
	while (t>1){
		if (f[t]>f[t+1]+1)
			f[t]=f[t+1]+1;
		else
			break;
		--t;
	}
	for (int i=2;i<=n;++i){
		f[i]=min(f[i],f[i-1]+1);
		f[a[i]]=min(f[a[i]],f[i]+1);
		t=a[i]-1;
		while (t>i){
			if (f[t]>f[t+1]+1)
				f[t]=f[t+1]+1;
			else
				break;
			--t;
		}
	}
	for (int i=1;i<=n;++i)
		printf("%d ",f[i]);
	printf("\n");
	return 0;
}
