/*********************************
Date: Fri Mar  9 16:41:12 CST 2018
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
int a[maxn],b[maxn];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;
	int t=1;
	LL l=0;
	LL r=0;
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for (int i=1;i<=m;++i)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;++i){
		l+=a[i];
		while (l>r){
			r+=b[t++];
		}
		if (l == r){
			l=r=0;
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}
