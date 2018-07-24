/*********************************
Date: Sun Mar 18 21:15:09 CST 2018
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
const int maxn =  100;
int a[maxn][maxn];
int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
struct Node
{
	int x,y,t,r;
	Node (int x=0,int y=0,int t=0,int r=0):x(x),y(y),r(r),t(t){}
};
int vs[maxn][maxn];
int bfs(int x,int y)
{
	CL(vs);
	queue<Node>Q;
	while (!Q.empty()) Q.pop();
	Q.push(Node(x,y,0,6));
	while (!Q.empty()){
		x = Q.front().x;
		y = Q.front().y;
		#ifdef TEST
		cout<<x<<" "<<y<<endl;
		#endif
		int t = Q.front().t;
		int r = Q.front().r;
		Q.pop();
		if (x<0 || x>=n || y<0 || y>=m || vs[x][y] >= r|| r==0) continue;
		if (a[x][y] == 0) continue;
		if (a[x][y] == 3) return t;
		if (a[x][y] == 4) r=6;
		vs[x][y] = r;
		for (int i=0;i<4;++i){
			Q.push(Node(x+dx[i],y+dy[i],t+1,r-1));
		}
	}
	return -1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int sx,sy;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				scanf("%d",&a[i][j]);
				if (a[i][j] == 2){
					sx=i;
					sy=j;
				} 
			}
		}
		int ans = bfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
