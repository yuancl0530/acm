/*********************************
Date: Fri Mar 16 16:01:45 CST 2018
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

int n;
int pos[maxn];
#define N 100000
int main()
{
	scanf("%d",&n);
	int x,y;

	for (int i=0;i<n;++i){
		scanf("%d%d",&x,&y);
		pos[N+x-y] = max(pos[N+x-y],y);
	}
	int r = 0;
	int f = 1;
	double ans =0;
	for (int i=0;i<=2*N;++i){
		if (!pos[i]) continue;
		if (f){
			ans = (double)pos[i]*pos[i];
			r=i+pos[i]*2;
			f=0;
		}
		else{
			if (i>=r){
				ans += (double)pos[i]*pos[i];
				r = i+pos[i]*2;
			}
			else if (i+2*pos[i]>r){
				double t = r-i;
				ans += (double)pos[i]*pos[i] - t*t/4.0;
				r = pos[i]*2+i;
			}
		}
	}
	printf("%.2lf\n",ans);
	return 0;
}
