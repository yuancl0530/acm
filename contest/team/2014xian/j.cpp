/*********************************
Date: Sat Apr  7 20:44:32 CST 2018
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
const int maxn = 1e5 + 100;
char s[20][20];
int dis[20][20];
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
struct Node
{
	int x1,x2,y1,y2;
}a[maxn];
int bfs(int u,int v)
{

}
int n,m;
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF){
		for (int i=0;i<n;++i){
			scanf("%s",s[i]);
		}
		for (int i=0;i<m;++i){
			scanf("%d%d%d%d",&a[i].x1.&a[i].y1,&a[i].x1,&a[i].y2);
		}
		for (int i=0;i<m;++i){
			for (int j=0;j<m;++j){
				if (i==j) continue;
				dis[i][j]=bfs(i,j);
			}
		}
	}
	return 0;
}
