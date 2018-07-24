/*********************************
Date: Fri Mar 30 14:02:24 CST 2018
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
char s[100];
int main()
{
	while (scanf("%s",s)!=EOF){
		int i=0;
		if (s[i]=='9')++i;
		for (;s[i];++i){
			int t=s[i]-'0';
			if (t>9-t)
				t=9-t;
			s[i]='0'+t;
		}
		printf("%s\n",s);
	}
	return 0;
}
