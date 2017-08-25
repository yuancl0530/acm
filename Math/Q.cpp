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
LL Abs(LL a)
{
	return a>0? a:-a;
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b == 0){
		x = 1;
		y = 0;
		return a;
	}
	LL d = exgcd(b,a%b,x,y);
	LL t = x;
	x = y;
	y = t - a/b*y;
	return d;
}
int main()
{
	LL a,b,c,x,y;
	while (cin >> a >> b >>c){
		if (a==0&&b==0)break;
		LL ta=a,tb=b;
		if (a<b)swap(a,b);
		if (b==0){
			x=c/a;
			y=0;
		}
		else{
			LL d = exgcd(a,b,x,y);
			x=x*c/d;
			y=y*c/d;
			LL p = b/d;
			LL q = a/d;
			LL t=(c/a-x)/p;
			LL x1=x+p*t;
			LL y1=y-q*t;
		//	cout <<"*"<<c/a<<" "<<x1<<" "<<y1<<endl;
			for (int i = t-10;i<=t+10;i++){
				if (Abs(x1)+Abs(y1)>Abs(x+p*i)+Abs(y-q*i)){
					x1=x+p*i;
					y1=y-q*i;
				}
				else if (Abs(x1)+Abs(y1) == Abs(x+p*i)+Abs(y-q*i)){
					if (Abs(a*x1)+Abs(b*y1)>Abs(a*(x+p*i))+Abs(b*(y-q*i))){
						x1=x+p*i;
						y1=y-q*i;
					}
				}
			}
			if (ta<tb)swap(x1,y1);
			x=Abs(x1),y=Abs(y1);
		}
		cout<<x<<" "<<y<<endl;
	}

	return 0;
}
