/*********************************
Date: Sun Nov 19 12:41:51 CST 2017
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

int main()
{
	int n;
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int t;
		if (n&1)
			t=n/2+2;
		else
			t=n/2+1;
		for (int i=1;i<=n;++i){
			if (i&1)
				printf("%d ",i/2+1);
			else
				printf("%d ",t+i/2-1);
		}
		printf("\n");
	}
	return 0;
}
