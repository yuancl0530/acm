/*********************************
Date: Tue Jan 30 21:48:16 CST 2018
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
int a[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	LL ans = 0;
	for (int i=0;k && i<n;++i,--k){
		if (a[i]<0)
			a[i] = -a[i];
		else if (k&1){
			if (i==0 || a[i] > a[i-1]) 
				a[i] = -a[i];
			else 
				a[i-1] = -a[i-1];
			break;
		}
		else 
			break;
	}
	for (int i=0;i<n;++i)
		ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}
