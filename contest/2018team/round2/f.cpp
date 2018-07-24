/*********************************
Date: Fri Apr 20 15:11:31 CST 2018
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
int dp[5050][5050];
int a[5050];

int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		for (int len = 1;len < n;++len){
			for (int i=1;i+len <= n;++i){
				int l = i;
				int r = i+len;
				dp[l][r] = max(dp[l+1][r],dp[l][r-1]);
				if (a[l] == a[r]){
					dp[l][r] = max(dp[l][r],1+dp[l+1][r-1]);
				}
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}
