/*********************************
Date: Fri Apr 13 13:07:02 CST 2018
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
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	int s,g;
	scanf("%d%d",&s,&g);
	if (s%g || s==g){
		printf("-1\n");
	}
	else {
		int a=g;
		int b=(s/g-1)*g;
		printf("%d %d\n",a,b);
	}
	return 0;
}
