/*********************************
Date: Mon Aug 21 15:46:21 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char G[20][20];
char s[3];
bool HitByGorR(int x,int y)
{
	for (int i=y;i>0;i--){
		if (G[x][i]!=0){
			if (G[x][i]=='G'||G[x][i]=='R')
				return true;
			break;
		}
	}
	for (int i=y;i<=10;i++){
		if (G[x][i]!=0){
			if (G[x][i]=='G'||G[x][i]=='R')
				return true;
			break;
		}
	}

	for (int i=x;i>0;i--){
		if (G[i][y]!=0){
			if (G[i][y]=='G'||G[i][y]=='R')
				return true;
			break;
		}
	}
	for (int i=x;i<10;i++){
		if (G[i][y]!=0){
			if (G[i][y]=='G'||G[i][y]=='R')
				return true;
			break;
		}
	}

	return false;
}
const int dx[]={2,2,1,-1,-2,-2,-1,1};
const int dy[]={-1,1,2,2,1,-1,-2,-2};
bool HitByH(int x,int y)
{
	for (int i=0;i<8;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (xx<=0||xx>9||yy<=0||yy>10)
			continue;
		if (dy[i]== 2 && G[xx][yy-1]) continue;
		if (dy[i]==-2 && G[xx][yy+1]) continue;
		if (dx[i]== 2 && G[xx-1][yy]) continue;
		if (dx[i]==-2 && G[xx+1][yy]) continue;
		if (G[xx][yy]=='H') return true;
	}
	return false;
}
bool HitByC(int x,int y)
{
	for (int i=x;i>0;i--){
		if (G[i][y]){
			for (int j=i-1;j>0;j--)
				if (G[j][y]){
					if(G[j][y]=='C') return true;
					break;
				}
			break;
		}
	}

	for (int i=x;i<10;i++){
		if (G[i][y]){
			for (int j=i+1;j<10;j++)
				if (G[j][y]){
					if (G[j][y]=='C')return true;
					break;
				}
			break;
		}
	}
	for (int i=y;i<=10;i++){
		if (G[x][i]){
			for (int j=i+1;j<=10;j++)
				if (G[x][j]){
					if (G[x][j]=='C') return true;
					break;
				}
			break;
		}
	}
	for (int i=y;i>0;i--){
		if (G[x][i]){
			for (int j=i-1;j>0;j--)
				if (G[x][j]){
					if (G[x][j]=='C')return true;
					break;
				}
			break;
		}
	}
	return false;
}
bool hit(int x,int y)
{
	char c=G[x][y];
	G[x][y]=0;
	if (HitByGorR(x,y)||HitByC(x,y)||HitByH(x,y)){
		G[x][y]=c;
		return true;
	}
	G[x][y]=c;
	return false;
}
const int dxx[]={1,0,-1,0};
const int dyy[]={0,-1,0,1};
bool solve(int x,int y)
{
	bool  ans=1;
	for (int i=0;i<4;i++){
		int xx=x+dxx[i];
		int yy=y+dyy[i];
		if (xx<4||xx>6||yy<1||yy>3)
			continue;
		if (!hit(xx,yy))
			ans=false;
	}
	return ans;
}
int main()
{
	int a,b;
	int n,x,y;
	while (scanf("%d%d%d",&n,&y,&x) != EOF){
		if (n==0)break;
		CL(G);
		for (int i=0;i<n;i++){
			scanf("%s%d%d",s,&a,&b);
			G[b][a]=s[0];
		}
		bool flag=solve(x,y);
		if (flag) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}
