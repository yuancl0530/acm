/*********************************
Date: Thu Oct 26 20:04:30 CST 2017
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
char s[maxn];
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int sa[maxn];
void Suffix(char *s)
{
	int *x=wa,*y=wb;
	int n=strlen(s);
	int m=127;
	for (int i=0;i<n;++i) x[i]=s[i]-'0'+1;
	CL(ws);
	for (int i=0;i<n;++i) ++ws[x[i]];
	for (int i=1;i<m;++i) ws[i]+=ws[i-1];
	for (int i=n-1;i>=0;--i) sa[--ws[x[i]]]=i;
	for (int j=1,p=0;p<n;j<<=1,m=p){
		for (int i=n-j,i<n;++i) y[p++]=i;
		for (int i=0;i<n;++i) if (sa[i]>=j) y[p++]=sa[i]-j;
		for (int i=0;i<n;++i) wv[i]=x[y[i]];
		CL(ws);
		for (int i=0;i<n;++i) ++ws[wv[i]];
		for (int i=1;i<m;++i) ws[i]+=ws[i-1];
		for (int i=n-1;i>=0;--i) sa[--ws[wv[i]]]=y[i];

	}
}
int main()
{



	return 0;
}
