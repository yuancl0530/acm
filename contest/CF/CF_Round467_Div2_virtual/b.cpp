/*********************************
Date: Sun Mar  4 14:24:05 CST 2018
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
int p;
bool is_prime(int a)
{
	int t = min((int)sqrt(a),p);
	for (int i=2;i<=t;++i){
		if (a%i==0)
			return false;
	}
	return true;
}
int main()
{
	int y;
	scanf("%d%d",&p,&y);
	int f = 0;
	for (int i=y;i>p;--i){
		if (is_prime(i)){
			printf("%d\n",i);
			f  = 1;
			break;
		}
	}
	if (!f)
		printf("-1\n");
	return 0;
}
