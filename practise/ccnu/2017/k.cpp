/*********************************
Date: Wed Apr 25 13:46:46 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
int b[100];
bool check(int l,int r)
{
	if (r-l>=60) return true;
	int t=0;
	for (int i=l;i<=r;++i){
		b[t++] = a[i];
	}
	sort(b,b+t);
	for (int i=2;i<t;++i){
		if (b[i] < b[i-1]+b[i-2]){
			return true;
		}
	}
	return false;
}
int main()
{
	int T;
	int n,m,op,x,y;
	scanf("%d",&T);
	int kase = 0;
	while (T--){
		printf("CASE #%d:\n",++kase);
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		while (m--){
			scanf("%d%d%d",&op,&x,&y);
			if (op==1){
				a[x] = y;
			}
			else{
				if (check(x,y)){
					printf("YES\n");
				}
				else{
					printf("NO\n");
				}
			}
		}
	}
	return 0;
}
