/*********************************
Date: Mon Nov 13 20:27:55 CST 2017
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
int a[maxn],b[maxn],Next[maxn];
void getnext(int *s,int n)
{
	int k=-1;
	Next[0]=k;
	for (int i=1;i<n;++i){
		while (k>=0 && s[i]!=s[k+1])
			k=Next[k];
		if (s[k+1]==s[i])
			++k;
		Next[i]=k;
	}
}
int KMPmatch(int *a,int *b,int n,int m)
{
	getnext(b,m);
	int k=-1;
	for (int i=0;i<n;++i){
		while (k>=0 && a[i]!=b[k+1])
			k=Next[k];
		if (a[i]==b[k+1])
			++k;
		if (k==m-1){
			return i-m+2;
		}
	}
	return -1;
}
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i)
			scanf("%d",&a[i]);
		for (int i=0;i<m;++i)
			scanf("%d",&b[i]);
		printf("%d\n",KMPmatch(a,b,n,m));
	
	}

	return 0;
}
