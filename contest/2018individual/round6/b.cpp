/*********************************
Date: Wed Apr 11 19:12:06 CST 2018
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
int a[maxn];
int main()
{
	int n;
	LL k;
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	LL t=1;
	while (t*(t+1)<2*k)
		++t;
	}
	t-=1;
	int id=k-t*(t+1)/2;
	if (id==0) id=n;
	printf("%d\n",a[id-1]);
	return 0;
}
