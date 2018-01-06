/*********************************
Date: Sat Aug 26 09:26:07 CST 2017
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
const int maxn = 1e2 + 100;
int sum[maxn][maxn];
int a[maxn][maxn];
int w,h;
void calsum()
{
	for (int i=1;i<=w;i++){
		for (int j=1;j<=h;j++){
			a[i][j]+=a[i][j-1];
			sum[i][j]=a[i][j]+sum[i-1][j];
		}
	}
}
int solve(int s,int t)
{
	int ans=0;
	for (int i=s;i<=w;i++){
		for (int j=t;j<=h;j++){
			ans=max(ans,sum[i][j]-sum[i-s][j]-sum[i][j-t]+sum[i-s][j-t]);
		}
	}
	return ans;
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n){
		CL(sum);
		CL(a);
		scanf("%d%d",&w,&h);
		int x,y;
		while (n--){
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		calsum();
		int s,t;
		scanf("%d%d",&s,&t);
		int ans=solve(s,t);
		printf("%d\n",ans);
	}


	return 0;
}
