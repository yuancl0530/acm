/*********************************
Date: Thu Oct  5 14:03:31 CST 2017
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
LL gcd(LL a,LL b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
    LL x,y,a,b;
	while (scanf("%lld%lld",&a,&b) != EOF){
		LL tmp=gcd(a,b);
		LL d=a*a-4*b*tmp;
		if (d<0){
			printf("No Solution\n");
			continue ;
		}
		LL dd=sqrt(d);
		if (dd*dd!=d){
			printf("No Solution\n");
			continue ;
		}
		if ((a-dd)%2!=0){
			printf("No Solution\n");
			continue ;
		}
		x=(a-dd)/2;
		y=a-x;
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
