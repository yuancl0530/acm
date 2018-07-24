/*********************************
Date: Mon Jul 23 12:39:00 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int x,y,t;
	friend bool operator < (Node a,Node b)
	{
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
}a[maxn];
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i = 0;i < 3*n;++i){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].t = i + 1;
		}
		sort(a,a+3*n);
		for (int i = 0; i < 3*n;i+=3)
			printf("%d %d %d\n",a[i].t,a[i+1].t,a[i+2].t);
			
	}
	return 0;
}
