/*********************************
Date: Sat Aug 26 09:02:54 CST 2017
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
const int maxn = 1e2 + 100;
int w,h;
int sum[maxn][maxn];
int lowbit(int x){return x&(-x);}
void update(int x,int y,int value)
{
	for (int i=x;i<=w;i+=lowbit(i)){
		for (int j=y;j<=h;j+=lowbit(j)){
			sum[i][j]+=value;
		}
	}
}
int query(int x,int y)
{
	int ret=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
			ret+=sum[i][j];
		}
	}
	return ret;
}
int solve(int x,int y)
{
	int ans = 0;
	for (int i=x;i<=w;i++){
		for (int j=y;j<=h;j++){
			ans=max(ans,query(i,j)-query(i-x,j)-query(i,j-y)+query(i-x,j-y));
		}
	}
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n){
		scanf("%d%d",&w,&h);
		int x,y;
		while (n--){
			scanf("%d%d",&x,&y);
			update(x,y,1);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		int ans=solve(s,t);
		printf("%d\n",ans);
	}
	return 0;
}
