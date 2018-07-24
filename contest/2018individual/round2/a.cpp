/*********************************
Date: Sat Mar 10 14:01:38 CST 2018
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
	int n,m;
	scanf("%d%d",&n,&m);
	if (n+1<m){
		printf("NO\n");
	}
	else {
		if (n+1 != m){
			for (int i=0;i<m;++i)
				printf("01");
			for (int i=0;i<n-m;++i)
				printf("0");
		}
		else{
			for (int i=0;i<n;++i){
				printf("10");
			}
			printf("1");
		}
	}
	return 0;
}
