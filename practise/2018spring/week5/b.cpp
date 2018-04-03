/*********************************
Date: Mon Apr  2 19:27:10 CST 2018
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
LL f[2][4];
LL solve(int n)
{
	f[0][1]=f[0][2]=f[0][3]=1;
	f[0][0]=0;
	for (int i=1;i<n;++i){
		int u=i&1;
		int v=(u+1)%2;
		LL tmp=0;
		for (int j=0;j<4;++j){
			tmp=(tmp+f[v][j])%mod;
		}
		for (int j=0;j<4;++j){
			f[u][j]=(tmp-f[v][j]+mod)%mod;
		}
	}
	return f[(n-1)&1][0];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",solve(n));
	return 0;
}
