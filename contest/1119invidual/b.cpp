/*********************************
Date: Sun Nov 19 19:37:30 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e7 + 100;
int a[maxn],n;
LL cnt[maxn],k;
bool check(int s)
{
	LL sum=0;
	CL(cnt);
	for (int i=0;i<n;++i){
		cnt[a[i]]++;
	}
	for (int i=1e7;i>=s;--i){
		if (i/2<s)
			sum+=cnt[i];
		else if (i%2==0){
			cnt[i/2]+=2*cnt[i];
		}
		else{
			cnt[i/2]+=cnt[i];
			cnt[i/2+1]+=cnt[i];
		}
	}
	if (sum>=k) return true;
	else return false;
}
int main()
{
	scanf("%d%lld",&n,&k);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int l,r,mid;
	l=1;
	r=1e7+1;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid))
			l=mid;
		else
			r=mid;
	}
	if (check(l))
		printf("%d\n",l);
	else
		printf("-1\n");
	return 0;
}
