/*********************************
Date: Fri Apr 13 16:19:41 CST 2018
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
int n,m;
bool check(int t)
{
	int cnt=0;
	for (int i=0;i<n;++i){
		if (t && a[i]>cnt){
			--t;
			++cnt;
		}
		else if (a[i]<=cnt){
			++cnt;
		}
		if (cnt>=m) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	int l=-1;
	int r=n;
	while (l+1<r){
		int mid=(l+r)/2;
		if (check(mid)){
			r=mid;
		}
		else {
			l=mid;
		}
	}
	printf("%d\n",r);
	return 0;
}
