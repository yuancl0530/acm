/*********************************
Date: Fri Sep 15 20:38:23 CST 2017
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
#define MP(a,b) make_pair(a,b>)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char mp[1010][1010];
int n,m;
int x,y;
int Index;
int cnt;
bool vs[1010][1010][4];
int ans[maxn];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int A[1010][1010];
struct Node
{
	int x;
	int y;
	Node (int a=0,int b=0)
	{
		x=a;
		y=b;
	}
};
void Num(int x,int y)
{
	queue<Node >Q;
	while (!Q.empty()) Q.pop();
	mp[x][y]=Index;
	Q.push(Node(x,y));
	for (;!Q.empty();Q.pop()){
		for (int i=0;i<4;i++){
			int xx=Q.front().x+dx[i];
			int yy=Q.front().y +dy[i];
			if (xx<0||yy<0||xx>=n||yy>=m)continue;
			if (mp[xx][yy]=='*') continue;
			if (A[xx][yy]) continue;
			A[xx][yy]=Index;
			Q.push(Node(xx,yy));
		}
	}
}
int main()
{
	int k;
	while (scanf("%d%d%d",&n,&m,&k) != EOF){
		CL(vs);
		for (int i=0;i<n;i++)
			scanf("%s",mp[i]);
		Index=0;
		CL(ans);
		for (int i=0;i<n;++i){
			for (int j=0;j<m;++j){
				if (mp[i][j]=='.'){
					++Index;
					Num(i,j);
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<m;j++){
				if (mp[i][j]=='*'){
					for (int p=0;p<4;p++){
						int xx=i+dx[p];
						int yy=j+dy[p];
						if (xx<0||yy<0||xx>=n||yy>=m) continue;
						if (mp[xx][yy]=='*')continue;
						ans[A[xx][yy]]++;
					}	
				}
			}
		}
		while (k--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",ans[mp[x-1][y-1]]);
		}
	}
	return 0;
}
