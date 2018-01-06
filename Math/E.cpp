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
LL exgcd(LL a,LL b,LL &x,LL& y)
{
	if (b==0){
		x=1,y=0;
		return a;
	}
	LL d = exgcd(b,a%b,x,y);
	LL t = x;
	x = y;
	y = t -a/b*y;
	return d;
}
int main()
{
	LL a1,a2,b1,b3,x,y,L,R;
	while (cin>>a1>>b1>>a2>>b2>>L>>R){
		LL d = exgcd(a1,-a2,x,y);
		if ((b2-b1)%d){
			cout<<0<<endl;
			continue;
		}
		LL lx,rx,ly,ry;
		lx = (L-b1)/a1;
		Rx = (R-b1)/a1;
		ly = (L-b2)/a2;
		ry = (R-b2)/a2;
		x*=(b2-b1)/d;
		y*=(b2-b1)/d;
		LL t1 = min(abs((rx-x)/p),abs((y-ry)/q));
		LL t2 = min(abs((lx-x)/p),abs((y-ly)/q));
	}
	return 0;
}
