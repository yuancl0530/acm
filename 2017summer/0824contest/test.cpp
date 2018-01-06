/*********************************
Date: Thu Aug 24 15:39:30 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
LL h[maxn];
LL b[maxn];
int main()
{
	h[0]=2;h[1]=3;h[2]=6;
	for (int i=3;i<=10;i++)
		h[i] = 4*h[i-1]+17*h[i-2]-12*h[i-3]-16;
	for (int i=1;i<10;i++)
		b[i]=3*h[i+1]*h[i]+9*h[i+1]*h[i-1]+9*h[i]*h[i]+27*h[i]*h[i-1]-18*h[i+1]-126*h[i]-81*h[i-1]+192;
	for (int i=1;i<10;i++)
		cout  <<h[i]<<endl;
	cout<<endl;
	for (int i=1;i<10;i++)
		cout<<(LL)sqrt(b[i])<<endl;


	return 0;
}
