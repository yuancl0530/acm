/*********************************
Date: Sat Mar 17 14:37:14 CST 2018
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
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int n,m;
LL solve(int s,int f,int t)
{
	if (s==f) return t;
	LL m = 2*n-2;
	LL tt = t%m;
	LL now;
	LL ans;
	if (tt+1<=n)
		now=tt+1;
	else 
		now=n-(tt-n+1);
	if (f>s){
		if (tt+1<=n){
			if (now<=s){
				ans = t+(f-now);
			}
			else{
				ans = t+(n-now)+(n-1)+f-1;
			}
		}
		else {
			ans = t+(now-1)+f-1;
		}
	}
	else {
		if (tt+1>=n){
			if (now>=s){
				ans = t+now-f;
			}
			else {
				ans = t+(now-1)+(n-1)+(n-f);
			}
		}
		else{
			ans = t+(n-now)+(n-f);
		}
	}
	return ans;

}
int main()
{	
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;++i){
		int s,f,t;
		scanf("%d%d%d",&s,&f,&t);
		printf("%lld\n",solve(s,f,t));
	}
	return 0;
}
