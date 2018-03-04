/*********************************
Date: Fri Sep 15 20:08:53 CST 2017
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
const int maxn = 1e6 + 100;
struct Node
{
	int x;
	int y;
	int i;
	double d;
	void cal()
	{
		if (x==0){
			if (y>0)
				d=0;
			else
				d=180;
		}
		else if (y==0){
			if (x>0)
				d=90;
			else 
				d=270;
		}
		else{
			double t=sqrt(x*x+y*y);
			if (x>0 && y>0){
				d=asin(x/t);
			}
			else if (x<0 && y>0){
				d=180-asin(-x/t);
			}
			else if (x<0 && y<0){
				d=180+asin(-x/t);
			}
			else{
				d=360-asin(x/t);
			}
				
		}
	}
	friend bool operator <(Node a,Node b){
		return a.d<b.d;
	}
};
Node a[maxn];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=0;i<n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].cal();
			a[i].i=i+1;
		}
		sort(a,a+n);
		double Min=INF;
		int ans_i=0,ans_j=0;
		for (int i=0;i<n;i++){
			for (int j=i+1;j<n;j++){
				double tmp=a[j].d-a[i].d;
				if (tmp>180) tmp=360-tmp;
				if (tmp<Min){
					Min=tmp;
					ans_i=i;
					ans_j=j;
				}
			}
		}
		int p=a[ans_i].i;
		int q=a[ans_j].i;

		printf("%d %d\n",a[ans_i].i,a[ans_j].i);
	}
	

	return 0;
}
