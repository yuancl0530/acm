/*********************************
Date: Sat Mar 10 10:47:13 CST 2018
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
const int maxn = 2e6 + 100;
int a[maxn];
int main()
{
	int len=0;
	int n;
	scanf("%d",&n);
	len=max(n,len);
	int t;
	for (int i=1;i<=n;++i){
		scanf("%d",&t);
		a[i]+=t;
	}
	scanf("%d",&n);
	len=max(n,len);
	for (int i=1;i<=n;++i){
		scanf("%d",&t);
		a[i]+=t;
	}
	while (1){
		int f=1;
		for (int i=1;i<=len;++i){
			if (a[i] && a[i+1]){
				int tmp=min(a[i],a[i+1]);
				a[i+2] = tmp;
				len=max(len,i+2);
				a[i]-=tmp;
				a[i+1]-=tmp;
				f=0;
			}
		}
		for (int i=len;i>=3;--i){
			
		}
	}
	return 0;
}
