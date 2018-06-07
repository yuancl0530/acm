/*********************************
Date: Sun Mar  4 14:57:11 CST 2018
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
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;

int main()
{
	LL k,d;
	double t;
	scanf("%lld%lld%lf",&k,&d,&t);
	double ans = 0;
	if (k%d==0){
		ans = t;
	}
	else{
		LL tmp = k/d*d+d;
		double tt = k+0.5*(tmp-k);
		LL x = (LL)t/tt;
		ans+=x*tmp;
	//	cout<<tmp<<endl;
		t -= x*tt;
		if (t<=k){
			ans+=t;
		}
		else{
			ans+=k+2*(t-k);
		}
	}
	printf("%.1lf\n",ans);
	return 0;
}
