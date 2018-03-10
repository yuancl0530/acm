/*********************************
Date: Fri Mar  9 13:16:03 CST 2018
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
const int maxn = 1e3 + 100;
int cnt[maxn][maxn];
char s[maxn][maxn];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={1,1,0,-1,-1,-1,0,1};
int Count(int x,int y)
{
	int ret = 0;
	for (int i=0;i<8;++i){
		if (s[x+dx[i]][y+dy[i]] == '*')
			++ret;
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (s[i][j] == '.')
				cnt[i][j] = Count(i,j);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (s[i][j] == '*')
				printf("*");
			else
				printf("%d",cnt[i][j]);
		}
		printf("\n");
	}
	return 0;
}
