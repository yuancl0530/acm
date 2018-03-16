/*********************************
Date: Fri Mar 16 13:59:59 CST 2018
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
char s[maxn];
int a[maxn];
int main()
{
	int T,n;
	scanf("%d",&T);
	int res;
	while (T--){
		res=0;
		scanf("%s",s);
		for (int i=0;s[i];++i)
			res = (res+s[i]-'0')%3;
		if (res == 0)
			printf("B\n");
		else 
			printf("A\n");
	}
	return 0;
}
