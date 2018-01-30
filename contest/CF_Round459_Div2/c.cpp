/*********************************
Date: Mon Jan 29 23:24:45 CST 2018
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
int dp[5010][5010];
int ml[5010];
int mr[5010];
int main()
{
	CL(dp);
	scanf("%s",s);
	int len = strlen(s);
	for (int i=0;i<len;++i){
		dp[i+1][i]=1;
		ml[i]=mr[i]=i;
	}
	for (int i=2;i<=len;i+=2){
		for (int l=0;i+l-1<len;++l){
			int r = l+i-1;
			if (dp[l+1][r-1] && (s[l]=='(' || s[l]=='?') && (s[r]==')' || s[r]=='?')){
				dp[l][r]=1;
				ml[l]=max(ml[i],r);
				mr[r]=min(mr[r],l);
			}
			else 
				dp[l][r]=0;
			if (dp[l][r]==0){
				for (int j=mr[r]-1;j<ml[l]+1;++j){
					if (dp[l][j] && dp[j+1][r]){
						dp[l][r]=1;
						mr[r]=l;
						ml[l]=r;
						break;
					}
				}
			}
		}
	}
	int ans=0;
	for (int i=0;i<len;++i)
		for (int j=i+1;j<len;++j)
			if (dp[i][j]) ++ans;
	cout<<ans<<endl;
	return 0;
}
