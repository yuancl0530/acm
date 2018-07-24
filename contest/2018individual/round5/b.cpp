/*********************************
Date: Fri Mar 30 14:10:28 CST 2018
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
const int maxn = 1e6 + 100;
struct fac
{
	int x;
	int y;
	friend bool operator == (fac a,fac b)
	{
		return a.x==b.x && a.y==b.y;
	}
	int gcd(int a,int b)
	{
		if (b==0) return a;
		return gcd(b,a%b);
	}
	void set(int a,int b)
	{
		if (a==0){
			this->x=0;
			this->y=1;
			return ;
		}
		if (a*b<0){
			if (a<0){
				a=-a;
				b=-b;
			}
		}
		else {
			a=abs(a);
			b=abs(b);
		} 
		int t=gcd(abs(a),b);
		a/=t;
		b/=t;
		this->x=a;
		this->y=b;
	}
	bool friend operator < (fac a,fac b)
	{
		LL t1=(LL)a.x*b.y;
		LL t2=(LL)b.x*a.y;
		if (a.y*b.y<0) return t1>t2;
		return t1<t2;
	}
}f[maxn];
int main()
{
	int n,x0,y0,x,y;
	scanf("%d%d%d",&n,&x0,&y0);
	int cnt=0;
	for (int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		if (x!=x0)f[cnt++].set(y-y0,x-x0);
	}
	sort(f,f+cnt);
	int tt =(int) (cnt!=n);
	cnt=unique(f,f+cnt)-f;
	printf("%d\n",cnt+tt);
	return 0;
}
