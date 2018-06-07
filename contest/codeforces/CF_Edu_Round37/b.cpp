/*********************************
Date: Fri Feb  2 23:00:34 CST 2018
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
struct Node
{
	int l,r;
	int i;
	int v;
	friend bool operator < (Node a, Node b)
	{
		if (a.l != b.l)
			return a.l < b.l;
		return a.i < b.i;
	}
}a[maxn];
int ans[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			a[i].i=i;
			scanf("%d%d",&a[i].l,&a[i].r);
		}
		sort(a,a+n);
		int t=1;
		for (int i=0;i<n;++i){
			if (t<=a[i].l){
				t = a[i].l;
				ans[a[i].i] = t;
				++t;
			}
			else if (t>a[i].l && t<=a[i].r)
				ans[a[i].i] = t++;
			else
				ans[a[i].i] = 0;
		}
		for (int i=0;i<n;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
