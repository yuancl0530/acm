/*********************************
Date: Fri Oct 13 19:05:25 CST 2017
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
int gcd(int a,int b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		for (int i=n/2;i>0;--i){
			int b=n-i;
			if (gcd(i,b)==1){
				printf("%d %d\n",i,b);
				break;
			}
		}
	}


	return 0;
}
