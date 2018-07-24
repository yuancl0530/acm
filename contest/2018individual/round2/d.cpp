/*********************************
Date: Sat Mar 10 17:16:33 CST 2018
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
char s[maxn];
int main()
{
	scanf("%s",s);
	int ans = strlen(s);
	int len = ans;
	for (int i=1;s[i];++i){
		if (s[i-1] != s[i]){
			ans = min(ans,max(i,len-i));
		}
	}
	printf("%d\n",ans);
	return 0;
}
