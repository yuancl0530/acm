/*********************************
Date: Sat Apr 14 14:34:45 CST 2018
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
#define ULL unsigned long long 
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	LL x,y;
}a[maxn];
LL cal(int x,int y,int z)
{
	Node aa;
	aa.x = a[y].x - a[x].x;
	aa.y = a[y].y - a[x].y;
	Node bb;
	bb.x = a[z].x - a[x].x;
	bb.y = a[z].y - a[x].y;
	return abs(aa.x*bb.y - aa.y*bb.x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	LL ans = 4e18;
	for (int i=0;i<n;++i){
		ans=min(ans,cal(i,(i-1+n)%n,(i+1)%n));
	}
	printf("%lld\n",ans);
	return 0;
}
