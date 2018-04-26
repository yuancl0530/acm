/*********************************
Date: Thu Apr 26 09:10:34 CST 2018
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
struct Node
{
	int x;
	ll c;
	friend bool operator < (Node a,Node b)
	{
		return a.x<b.x;
	}
}c[maxn];
ll sum[maxn];
ll dp[maxn];
int main()
{
	
	int n;
	while (scanf("%d",&n)!=EOF){
		for (int i=1;i<=n;++i){
			scanf("%d%lld",&c[i].x,&c[i].c);
		}
		sort(c+1,c+n+1);
		for (int i=1;i<=n;++i){
			sum[i]=sum[i-1]+c[i].x;
		}
		dp[1] = c[1].c;
		for (int i=2;i<=n;++i){
			dp[i] = dp[i-1]+c[i].c;
			for (int j=1;j<i;++j){
				dp[i] = min(dp[i],dp[j-1]+c[j].c+(sum[i]-sum[j]-(ll)(i-j)*c[j].x));
			}
			//cout<<"*"<<dp[i]<<endl;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}
