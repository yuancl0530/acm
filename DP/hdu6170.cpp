/*********************************
Date: Wed Aug 23 15:43:06 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 3e3 + 100;
char a[maxn];
char b[maxn];
bool dp[maxn][maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		CL(a);
		CL(b);
		CL(dp);
		scanf("%s%s",a+1,b+1);
		int lena=strlen(a+1);
		int lenb=strlen(b+1);
		dp[0][0]=true;
		for (int i=1;i<=lena;i++){
			for (int j=1;j<=lenb;j++){
				if(b[j]=='.'){
					dp[i][j] |= dp[i-1][j-1];
				}
				else if (b[j]=='*'){
					dp[i][j] |= dp[i][j-1]|dp[i][j-2];
					dp[i][j] |= dp[i-1][j]&&(a[i]==a[i-1]);
				}
				else {
					if (b[j-1]=='*') 
						dp[i][j]|=dp[i-1][j-3]&&(a[i]==b[j]);
					dp[i][j] |= dp[i-1][j-1]&&(a[i]==b[j]);
				}
			}
		}
		if (dp[lena][lenb])
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
