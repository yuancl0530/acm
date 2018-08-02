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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 60 + 5;
char G[maxn][maxn];
int n,m;
bool vs[maxn][maxn];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ans;
int fx,fy;
void dfs(int x,int y,int cnt = 0)
{
	if (ans || x < 0 || x >= n || y >= m || y < 0)
		return ;
	if (G[x][y] != G[fx][fy]) return;
		if (cnt != 2&&vs[x][y] && x == fx && y == fy){
		ans =  1;return;
	}
	if (vs[x][y])
		return ;
//	cout << x << ','<<y<<endl;
	vs[x][y] = 1;
	for (int i = 0;i < 4;i++){
		dfs(x+dx[i],y+dy[i],cnt+1);
	}
	vs[x][y] = 0;
}
int main()
{

	while (scanf("%d%d",&n,&m) != EOF){
		for (int i = 0;i < n;i++){
			scanf("%s",G[i]);
		}
		CL(vs);
		ans = 0;

		for (int i = 0;!ans && i < n;i++){
			for (int j = 0;!ans && j < m;j++){
				fx = i;
				fy = j;
			//	CL(vs);
				dfs(i,j);
			}
		}
		if (ans){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}
