/*********************************
Date: Mon Aug 21 10:00:35 CST 2017
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
const int maxn = 2e2 + 100;
struct Node
{
	int x,y;
	Node(int xx=0,int yy=0)
	{
		x=xx;
		y=yy;
	}
}; 
struct Rec
{
	int x1,y1,x2,y2;
	Rec(int a=0,int b=0,int c=0,int d=0)
	{
		x1=a;
		y1=b;
		x2=c;
		y2=d;
	}
	friend bool inrec(Rec a,int x,int y)
	{
		if (x>=a.x1&&x<=a.x2&&y>=a.y1&&y<=a.y2)
			return true;
		return false;
	}	
	friend bool Inrec(Rec a,int x,int y)
	{
		if (x>a.x1&&x<a.x2&&y>a.y1&&y<a.y2)
			return true;
		return false;
	}

	friend bool inrec(Rec a,Rec b)
	{
		if ((b.x1>=a.x1&&b.x1<=a.x2 || b.x2>=a.x1&&b.x2<=a.x2)&&b.y1<=a.y1&&b.y2>=a.y2)
			return true;
		if ((b.y1>=a.y1&&b.y1<=a.y2 || b.y2>=a.y1&&b.y2<=a.y2)&&b.x1<=a.x1&&b.x2>=a.x2)
			return true;
		if (inrec(a,b.x1,b.y1)||inrec(a,b.x1,b.y2)||inrec(a,b.x2,b.y1)||inrec(a,b.x2,b.y2))
			return true;
		return false;
	}
	friend bool check(Rec a,Rec b)
	{
		if (inrec(b,a)||inrec(a,b))
			return false;
		return true;
	}
	friend bool allin(Rec a,Rec b)
	{
		if (Inrec(a,b.x1,b.y1)&&Inrec(a,b.x1,b.y2)&&Inrec(a,b.x2,b.y1)&&Inrec(a,b.x2,b.y2))
			return true;
		return false;
	}
	int area()
	{
		return (x2-x1)*(y2-y1);
	}
};
bool c[maxn][maxn];
vector<Rec>rec;
vector<Node>node;
void getRec()
{
	for (int i=0;i<node.size();i++){
		//cout<<node[i].x<<" "<<node[i].y<<endl;
		for (int j=0;j<node.size();j++){
			if (node[i].y>=node[j].y || node[j].x<=node[i].x)
				continue;
			if (c[node[i].x][node[j].y]&&c[node[j].x][node[i].y])
				rec.push_back(Rec(node[i].x,node[i].y,node[j].x,node[j].y));
		}
	}
}
int solve()
{
	int ans=0;
	for (int i=0;i<rec.size();i++){
		for (int j=i+1;j<rec.size();j++){
			if (allin(rec[i],rec[j])  ||  allin(rec[j],rec[i]))
				ans=max(ans,max(rec[i].area(),rec[j].area()));
			else if (check(rec[i],rec[j])){
				ans=max(ans,rec[i].area()+rec[j].area());
			}
		}
	}
	return ans;
}
int main()
{
	int n,x,y;
	while (scanf("%d",&n) != EOF){
		if (n==0)break;
		CL(c);
		rec.clear();
		node.clear();
		for (int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			node.push_back(Node(x,y));
			c[x][y]=1;
		}
		getRec();
		int ans=solve();
		if (ans)
			printf("%d\n",ans);
		else
			printf("imp\n");
	}


	return 0;
}
