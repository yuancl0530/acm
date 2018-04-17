/*********************************
Date: Wed Apr 11 19:51:15 CST 2018
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
LL a[maxn],b[maxn];
int n,k;
bool check(LL t)
{
	LL kk=k;
	for (int i=0;i<n;++i){
		if (a[i]*t>b[i]){
			kk-=a[i]*t-b[i];
		}
		if (kk<0) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	for (int i=0;i<n;++i){
		scanf("%lld",&b[i]);
	}
	LL l=0;
	LL r=1e10;
	while (l+1<r){
		LL mid=(l+r)/2;
		if (check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	printf("%lld\n",l);
	return 0;
}
