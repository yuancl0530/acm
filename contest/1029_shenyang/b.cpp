/*********************************
Date: Sun Oct 29 12:22:23 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int ans=0;
		scanf("%s",s);
		for (int i=0;s[i];++i)
			if (s[i]=='H')
				++ans;
			else if (s[i]=='O')
				ans+=16;
			else 
				ans+=12;
		printf("%d\n",ans);
	}
	return 0;
}
