/*********************************
Date: Thu Feb  1 00:06:00 CST 2018
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
int a[maxn],b;
int n,m;
int bSearch(int key)
{
	int l=0;
	int r=n;
	int mid;
	while (l+1 < r){
		mid = (l+r)>>1;
		if (a[mid] <= key)
			l=mid;
		else
			r=mid;
	}
	if (a[l] == key)
		return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n);
	scanf("%d",&m);
	int ans=0;
	for (int i=0;i<m;++i){
		scanf("%d",&b);
		if (bSearch(b))
			++ans;
	}
	printf("%d\n",ans);

	return 0;
}
