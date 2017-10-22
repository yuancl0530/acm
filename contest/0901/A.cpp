/*********************************
Date: Fri Sep  1 12:04:18 CST 2017
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
int main()
{
	int T;
	scanf("%d",&T);
	int t=0;
	while (T--){
		int n;
		scanf("%d",&n);
		int a;
		bool flag=1;
		for (int i=0;i<n;i++){
			scanf("%d",&a);
			if (a%3)flag=0;
		}
		if (flag)
			printf("Case #%d: Yes\n",++t);
		else
			printf("Case #%d: No\n",++t);
	}


	return 0;
}
