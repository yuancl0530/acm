/*********************************
Date: Tue Mar  6 10:42:15 CST 2018
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
LL a[maxn],s[maxn];
LL sum(int l,int r)
{
	return s[r]-s[l];
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;++i)
		s[i] = s[i-1]+a[i-1];
	int p = 0;
	LL Max = -sum(0,n);
	int s0,s1,s2;
	s0=s1=s2=0;
	for (int i=0;i<=n;++i){
		p = i;
		for (int j=i;j<=n;++j){
			if (sum(0,j)<sum(0,p)) p = j;
			LL tmp  = sum(0,i) - sum(i,p) + sum(p,j) - sum(j,n);
			if (tmp > Max){
				Max = tmp;
				s0 = i;
				s1 = p;
				s2 = j;
			}
		}
	}
	printf("%d %d %d\n",s0,s1,s2);
	return 0;
}
