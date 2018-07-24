/*********************************
Date: Fri Apr 20 15:35:24 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
double v[maxn];
double a[maxn];
int n;
double f;
bool check(double t)
{
	bool ret = true;
	double res = 0;
	for (int i = 1;i<=n;++i){
		a[i] = 0;
		a[i] += t*f + res;
		if (a[i]>v[i]){
			res = a[i]-v[i];
		}
		else{
			res = 0;
		}
		if (a[i]<v[i]) ret = false;
	}
	return ret;
}
int main()
{
	while (scanf("%d%lf",&n,&f) != EOF){
		double t = 0;
		for (int i=1;i<=n;++i){
			scanf("%lf",&v[i]);
			t = max(t,v[i]/f);
		}
		double l = 0;
		double r = t+1;
		double mid;
		while (r-l>=1e-6){
			mid = (l+r)/2;
			if (check(mid) || a[n]>=v[n]){
				r = mid;
			}
			else {
				l = mid;
			}
		}
		double ans = r;
		l = 0;
		r = t+1;
		while (r-l>=1e-6){
			mid = (l+r)/2;
			if (check(mid)){
				r = mid;
			}
			else {
				l = mid;
			}
		}
		double ans2 = r;
		printf("%.7lf %.7lf\n",ans,ans2);
	}
	return 0;
}
