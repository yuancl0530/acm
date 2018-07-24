/*********************************
Date: Mon Mar  5 19:25:48 CST 2018
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
const int maxn = 1e6 + 100;

int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	int p = 1<<17;
	int t=0;
	for (int i=0;i<=n;++i)
		t^=i;
	if (n == 1){
		printf("YES\n%d\n",x);
	}
	else if (n == 2){
		if (x==0)
			printf("NO\n");
		else {
			printf("YES\n0 %d\n",x);
		}
	}
	else {
		printf("YES\n");
		bool f = 1;
		int m=t^n^x;
		for (int i=1;i<n;++i){
			if (i!=m && f){
				printf("%d ",p^i);
				f = 0;
			}
			else
				printf("%d ",i);
		}
		printf("%d\n",n^t^p^x);
	}
	return 0;
}
