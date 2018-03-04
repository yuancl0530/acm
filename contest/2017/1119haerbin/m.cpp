/*********************************
Date: Sun Nov 19 15:45:09 CST 2017
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
#include <ctime>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
void Cal(double x1,double y1,double x2,double y2,double x3,double y3,double &x,double &y)
{
	double a1 = 2*(x1-x2);
	double b1 = 2*(y1-y2);
	double c1 = x1*x1-x2*x2+y1*y1-y2*y2;
	double a2 = 2*(x2-x3);
	double b2 = 2*(y2-y3);
	double c2 = x2*x2-x3*x3+y2*y2-y3*y3;
	double d  = a1*b2-b1*a2;
	double d1 = c1*b2-b1*c2;
	double d2 = a1*c2-a2*c1;
	x = d1/d;
	y = d2/d;
}
double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct Node 
{
	double x,y;
}a[maxn];
int t1,t2,t3,n;
double Abs(double x)
{
	if (x<0)
		return -x;
	return x;
}
bool check()
{
	double x;
	double y;
	int cnt=3;
	Cal(a[t1].x,a[t1].y,a[t2].x,a[t2].y,a[t3].x,a[t3].y,x,y);
	if (Abs(x)>1e9 || Abx(y)>1e9) return false;
	double d=dis(a[t1].x,a[t1].y,x,y);
	if (d>1e9) return false;
	for (int i=0;i<n;++i){
		if (i==t1 || i==t2 || i==t3) continue;
		if (Abs(d-dis(a[i].x,a[i].y,x,y)) <= 0.001)
			cnt++;
	}
	int t=n/2;
	if (n%2)++t;
	if (cnt>=t){
		printf("%.3lf %.3lf %.3lf\n",x,y,d);
		return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		if (n==1){
			printf("%.3lf %.3lf %.3lf\n",a[0].x,a[0].y,0.0);
		}
		else if (n<=4){
			double xx=(a[0].x+a[1].x)/2;
			double yy=(a[0].y+a[1].y)/2;
			double d=dis(a[0].x,a[0].y,xx,yy);
			printf("%.3lf %.3lf %.3lf\n",xx,yy,d);
		}
		else if (n<=100){
			int ff=1;
			for (int i=0;ff && i<n;++i){
				for (int j=i+1;ff && j<n;++j){
					for (int k=j+1;ff && k<n;++k){
						t1=i,t2=j,t3=k;
						if (check())ff=0;
					}
				}
			}
		
		}
		else{
			srand((int)time(0));
			do{
				t1=rand()%n;
				t2=rand()%n;
				while (t1 == t2)
					t2=rand()%n;
				t3=rand()%n;
				while (t3==t1 || t3==t2)
					t3=rand()%n;
			}while (!check());
		}
	}
	return 0;
}
