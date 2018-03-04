/*********************************
Date: Sun Oct 29 14:49:03 CST 2017
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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
const double PI=acos(-1);
double f(double x,double a,double b)
{
	double ret= b*sqrt(1.0-x*x/(a*a));
	return ret;
}
double jifen(double t,double a,double b)
{
	double res=a-t;
	double ans=0.0;
	int n=100000;
	double tt=res/n;
	for (int i=1;i<=n;++i){
		ans+=f(t+tt*i,a,b)*tt;
	}
	return 2*ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		double h;
		scanf("%lf",&h);
		double ans;
		if (h>=1){
			double tmp=4.0-2*h;
			double a=sqrt(tmp*tmp+40)/2;
			double b=1.0;
			ans=a*b*PI;
		}
		else{
			double tmp=4.0/h;
			double a=sqrt(tmp*tmp+4.0)/2;
			double b=1.0;
			ans=jifen(a-a*h,a,b);
		}
		printf("%.5lf\n",ans);
	}
	return 0;
}
