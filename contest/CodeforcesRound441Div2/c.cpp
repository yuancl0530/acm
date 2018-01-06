/*********************************
Date: Mon Oct 16 19:38:05 CST 2017
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
const int maxn = 1e6 + 100;
bool check(int n,int i)
{
	int t=n-i;
	int sum=0;
	while (t){
		sum+=t%10;
		t/=10;
	}
	if (sum==i) return true;
	return false;
}
int ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	for (int i=0;i<=81 && i<=n;++i){
		if (check(n,i))
			ans[cnt++]=n-i;
	}
	printf("%d\n",cnt);
	sort(ans,ans+cnt);
	for (int i=0;i<cnt;++i)
		printf("%d\n",ans[i]);
	return 0;
}
