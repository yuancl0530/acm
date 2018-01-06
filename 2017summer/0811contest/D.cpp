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
const int maxn = 1e6 + 100;
struct Node
{
	int x;
	int y;
}s[200];
int a,b;
bool check(int x1,int y1,int x2,int y2)
{
	if (y1+y2 <= b && max(x1,x2) <= a)
		return 1;
	if (y1+y2 <= a && max(x1,x2) <= b)
		return 1;
	if (x1+x2 <= b && max(y1,y2) <= a)
		return 1;
	if (x1+x2 <= a && max(y1,y2) <= b)
		return 1;
	if (x1+y2 <= b && max(x2,y1) <= a)
		return 1;
	if (x1+y2 <= a && max(x2,y1) <= b)
		return 1;
	if (x2+y1 <= b && max(y2,x1) <= a)
		return 1;
	if (x2+y1 <= a && max(y2,x1) <= b)
		return 1;
	return 0;
}
int main()
{
	int n;
	while (scanf("%d%d%d",&n,&a,&b) != EOF){
		for (int i = 0;i < n;i++){
			scanf("%d%d",&s[i].x,&s[i].y);
		}
		int ans = 0;
		for (int i = 0;i < n;i++){
			for (int j = i+1;j < n;j++){
				if (check(s[i].x,s[i].y,s[j].x,s[j].y)){
					ans = max(ans,s[i].x*s[i].y+s[j].x*s[j].y);
				}
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}
