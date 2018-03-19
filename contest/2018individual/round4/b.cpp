/*********************************
Date: Sat Mar 17 15:59:09 CST 2018
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
const int maxn = 1e7+10;
#define N 10000000
bool f[maxn];
int main()
{
	int a,b;
	int m;
	scanf("%d%d%d",&a,&b,&m);
	int t = min(m,b);
	for (int i=0;i<=t;++i)
		f[i%m] = 1;
	t = min(m,a);
	int ff = 0;
	int ans = -1;
	int tt=1e9;
	for (int i=0;i<=t;++i){
		int x =(LL)i*tt%m;
		x = (m-x)%m;
		if (!f[x]){
			ans=i;
			break;
		}
	}
	if (ans==-1)
		printf("2");
	else {
		printf("1 %09d\n",ans);
	}
	return 0;
}
