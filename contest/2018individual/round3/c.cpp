/*********************************
Date: Fri Mar 16 14:37:41 CST 2018
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
const int maxn = 1e4 + 100;
LL f[1001][10000];
#define N 9000
void init()
{
	for (int i=0;i<=9;++i)
		f[1][i]=1;
	for (int i=2;i<=1000;++i){
		for (int j=0;j<=N;++j){
			for (int k=0;k<=9 && k<=j;++k){
				f[i][j] = (f[i][j] + f[i-1][j-k])%mod;
			}
		}
	}
}
LL solve(int n)
{
	LL ans = 0;
	if (n==1) return 9;
	for (int i=1;i<=N;++i){
		for (int j=1;j<=9 && j<= N;++j){
			ans = (ans + f[n-1][i-j]*f[n][i]%mod)%mod;
		}
	}
	return ans;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	printf("%lld\n",solve(n));
	return 0;
}
