/********************************
Date: Sun Mar 18 21:44:20 CST 2018
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
const int maxn = 100;
char a[maxn][maxn];
int ans = 0;
int n;
bool vs[maxn][maxn];
bool check(int x,int y)
{
	for (int i=0;i<n;++i){
		if (vs[x][i] || vs[i][y])
			return false;
	}
	return true;
}
void dfs(int x,int y,int k)
{
	if (!check(x,y)) return ;
	vs[x][y] = 1;
	if (k==1){
		++ans;
	}
	else {
		for (int i=x+1;i<n;++i){
			for (int j=0;j<n;++j){
				if (a[i][j] == '#')
					dfs(i,j,k-1);
			}
		}
	}
	vs[x][y] = 0;
}
int main()
{
	int k;
	while (scanf("%d%d",&n,&k)!=EOF && n!=-1){
		for (int i=0;i<n;++i){
			scanf("%s",a[i]);
		}
		ans = 0;
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j){
				if (a[i][j] == '#'){
					dfs(i,j,k);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
