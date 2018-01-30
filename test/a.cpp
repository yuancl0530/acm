/*********************************
Date: Tue Jan 30 22:10:34 CST 2018
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
const int maxn = 0 + 100;
int a[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int sum=0;
	int ans=0;
	res = k;
	for (int i=0;i<n;++i){
		if (sum+res>=m)
			break;
		sum+=a[i];
		++ans;
		if (i+1>k)
			--sum;
		if (res) --res;
	}
	if (sum+res>=m)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
