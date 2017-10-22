/*********************************
Date: Mon Oct 16 20:14:54 CST 2017
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
int a[maxn],p[maxn];
bool vs[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&p[i]);
	a[0]=1;
	int cnt=0;
	int nn=n+1;
	int last=a[0];
	for (int i=1;i<=n;i++){
		vs[p[i]]=1;
		++cnt;
		if (p[i]+1==nn){
			while (vs[nn-1] && nn>1){
				--nn;
				--cnt;
			}
			a[i]=cnt+1;
		}
		else{
			a[i]=cnt+1;
		}
	}
	for (int i=0;i<=n;++i)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
