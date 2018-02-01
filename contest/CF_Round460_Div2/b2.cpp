/*********************************
Date: Wed Jan 31 23:38:55 CST 2018
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
bool check(int a)
{
	int res=0;
	while (a){
		res+=a%10;
		a/=10;
	}
	return res == 10;
}
int main()
{
	int i=1;
	int cnt=0;
	while (cnt<10000){
		if (check(i))
			++cnt;
		++i;
	}


	return 0;
}
