/*********************************
Date: Wed Apr 25 19:47:41 CST 2018
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
int sum[maxn];
char s[maxn];
int n;
bool check(int k)
{
	int t = n/k;
	for (int i=t;i<=n;i+=t){
		if (sum[i]-sum[i-t] == t){
			return false;
		}
	}
	return true;
}
int main()
{
	int T,t;
	int kase = 0;
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		n = strlen(s+1);
		for (int i=1;s[i];++i){
			sum[i] = sum[i-1] + ((s[i]-'0')^1);
		}
		int ans=-1;
		for (int i=n;i>0;--i){
			if (n%i==0 && check(i)){
				ans = i;
				break;
			}
		}
		printf("CASE #%d: %d\n",++kase,ans);
	}
	return 0;
}
