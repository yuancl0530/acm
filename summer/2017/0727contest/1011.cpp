#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
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
#define Cl(a,b) memset(a,b,sizeof(b))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e3 + 100;
struct Node 
{
	int x;
	int y;
}a[maxn];
bool cmp(Node a,Node b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else 
		return a.y < b.y;
}
int Map[maxn][maxn];
int main()
{
	int x,y;
	int n;
	while (scanf("%d",&n) != EOF){
		CL(Map);
		LL ans = 0;
		for (int i = 0;i < n;i++){
			scanf("%d%d",&x,&y);
			x += 200;
			y += 200;
			Map[x][y] = 1;
			a[i].x = x;
			a[i].y = y;
		}
		sort(a,a+n,cmp);
		for (int i = 0;i < n;i++){
			for (int j = i + 1;j < n;j++){
				if (a[i].x == a[j].x || a[i].y  > a[j].y)
					continue;
				else{
					int dx = a[j].x - a[i].x;
					int dy = a[j].y - a[i].y;
					int x3 = a[j].x - dy;
					int y3 = a[j].y + dx;
					if (x3 >= 0 && y3 >= 0 && Map[x3][y3]){
						int x4 = a[i].x - dy;
						int y4 = a[i].y + dx;
						if (x4 >= 0 && y4 >= 0 && Map[x4][y4]){
							ans++;
						//	cout << x3 <<","<<y3<<" "<<x4<<","<<y4<<endl;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	
	}
	return 0;
}
