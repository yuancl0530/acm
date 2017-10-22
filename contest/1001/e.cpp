/*********************************
Date: Sun Oct  1 21:36:34 CST 2017
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
char s[maxn];
bool check(int t)
{
	int start=0;
	int p=0;
	int len=strlen(s);
	while (start<len){
		while (p<len && s[p]!='P') ++p;
		while (start<p && s[start] != '*') ++start;
		if (p<start)
			start=p;
		if (p==len && start!=len) return false;
		if (p-start>t) return false;
		start=max(start+t-(p-start),p+(t-(p-start))/2)+1;
		++p;
	}
	return true;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF){
		scanf("%s",s);
		int l=0;
		int r=2*n;
		int mid;
		while (l+1<r){
			mid=(l+r)>>1;
			if (check(mid))
				r=mid;
			else
				l=mid;
		}
		cout<<r<<endl;
	}
	return 0;
}
