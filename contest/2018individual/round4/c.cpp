/*********************************
Date: Sat Mar 17 14:04:30 CST 2018
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
const int maxn = 5050;
char s[maxn][maxn];
vector<int>V[maxn];
int ans[10];
bool f=0;
void dfs(int u,int ss,int t=1)
{
	if (f) return ;
	ans[t] = u;
	for (int i=0;i<V[u].size();++i){
		if (t==2){
			if (s[V[u][i]][ss] == '1'){
				f=1;
				ans[3] = V[u][i];
				return ;
			}
		}
		else
			dfs(V[u][i],ss,t+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%s",s[i]);
	int m = strlen(s[0]);
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j)
			if (s[i][j] == '1')
				V[i].push_back(j);
	}
	for (int i=0;i<n;++i){
		dfs(i,i);
		if (f) break;
	}
	if (!f)
		printf("-1\n");
	else{
		for (int i=1;i<=3;++i)
			printf("%d ",ans[i]+1);
		printf("\n");
	}
	return 0;
}
