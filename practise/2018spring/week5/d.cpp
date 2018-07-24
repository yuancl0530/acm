/*********************************
Date: Tue Apr  3 09:10:26 CST 2018
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
int n,m,k;
int a[maxn];
bool check(int t)
{
	int now=m;
	int cnt=k;
	for (int i=0;i<n;++i){
		if (a[i]>=now){
			--cnt;
			now=m;
			if (cnt<=0) return false;
		}
		else {
			now-=a[i];
			now+=t;
			now=min(now,m);
		}
	}
	return true;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int cnt=0;
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		if (a[i]>=m) ++cnt;
	}
	int ans;
	if (cnt>=k){
		ans=-1;
	}
	else {
		int l=0;
		int r=100000;
		while (l+1<r){
			int mid=(l+r)/2;
			if (check(mid)){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		ans=r;
	}
	printf("%d\n",ans);
	return 0;
}
