/*********************************
Date: Fri Feb  2 23:43:09 CST 2018
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
char s[maxn];
int dl[maxn],dr[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	scanf("%s",s);
	for (int i=0;s[i];++i){
		if (s[i] == '1')
			dl[i+1]=dl[i]+1;
	}
	for (int i=n-1;i>0;--i){
		if (s[i-1] == '1')
			dr[i-1]=dr[i] + 1;
	}
	int f=1;
	for (int i=0;f && i<n;++i){
		if (i+1 < a[i]){
			if (i+1+dr[i]>=a[i])
				continue;
			else
				f=0;
		}
		else if (i+1 > a[i]){
			if (i+1-dl[i] <=a[i])
				continue;
			else
				f=0;
		}
	}
	if (f)
		printf("YES\n");
	else 
		printf("NO\n");
	return 0;
}
