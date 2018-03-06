/*********************************
Date: Tue Mar  6 16:36:11 CST 2018
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
int n,d,t,ans1,ans0;
void print(const char *s)
{
	printf("? %s\n",s);
	fflush(stdout);
}
void solve0()
{
	int l=0;
	int r=n;
	while (l+1<r){
		int mid = (l+r)>>1;
		for (int i=0;i<n;++i) s[i] = '0';
		for (int i=l;i<mid;++i) s[i] = '1';
		print(s);
		scanf("%d",&t);
		if (d-t == mid-l)
			l = mid;
		else
			r = mid;
	}
	ans0= l+1;
}
void solve1()
{
	int l=0;
	int r=n;
	while (l+1<r){
		int mid = (l+r)>>1;
		for (int i=0;i<n;++i) s[i] = '0';
		for (int i=l;i<mid;++i) s[i] = '1';
		print(s);
		scanf("%d",&t);
		if (t-d == mid-l)
			l = mid;
		else
			r = mid;
	}
	ans1 = l+1;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		s[i] = '0';
	print(s);
	scanf("%d",&d);

	s[0] = '1';
	print(s);
	scanf("%d",&t);

	if (t<d){
		ans1 = 1;
		solve0();
	}
	else {
		ans0 = 1;
		solve1();
	}
	printf("! %d %d\n",ans0,ans1);
	return 0;
}
