/*********************************
Date: Fri Mar  9 16:11:20 CST 2018
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
	int l,r,a;
	scanf("%d%d%d",&l,&r,&a);
	if (l>r)
		swap(l,r);
	int ans;
	int res = r-l;
	if (res>=a)
		ans=l+a;
	else{
		a-=res;
		ans=r+a/2;
	}
	printf("%d\n",ans*2);
	return 0;
}
