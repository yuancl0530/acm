/*********************************
Date: Wed Oct 11 15:39:15 CST 2017
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
const int maxn = 2020;
char s[maxn][maxn];
vector<int>edge[2][maxn];
int dis[maxn];
bool bfs(int k,int s)
{
	queue<int>Q;
	CL(dis);
	while (!Q.empty()) Q.pop();
	Q.push(s);
	dis[s]=1;
	for (;!Q.empty();Q.pop()){
		int t=Q.front();
		for (int i=0;i<edge[k][t].size();++i){
			int tt=edge[k][t][i];
			if (!dis[tt]) dis[tt]=dis[t]+1;
			else continue;
			if (dis[tt]>2)return false ;
			Q.push(tt);
		}
	}
	return true;
}
void init()
{
	for (int i=0;i<maxn;++i){
		edge[1][i].clear();
		edge[0][i].clear();
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		init();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				if (s[i][j]=='P')
					edge[0][i].push_back(j);
				else if (s[i][j]=='Q')
					edge[1][i].push_back(j);
		bool f1=true,f2=true;
		for (int i=1;i<=n;++i){
			if (edge[0][i].size())
				f1=bfs(0,i);
			if (edge[1][i].size())
				f2=bfs(1,i);
			if (!(f1&&f2)) break;
		}
		if (f1&&f2)
			printf("T\n");
		else 
			printf("N\n");
	}
	return 0;
}
