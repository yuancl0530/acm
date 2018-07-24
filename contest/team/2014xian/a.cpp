/*********************************
Date: Tue Apr  3 18:32:39 CST 2018
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
char s[maxn];
const char ss[]="doge";
int Count()
{
	int ret=0;
	for (int i=0;s[i];++i){
		if (tolower(s[i])==ss[0]){
			int f=1;
			int j;
			for (j=1;s[i+j]&&j<4;++j){
				if (tolower(s[i+j])!=ss[j]){
					f=0;
					break;
				}
			}
			if (j==4 && f) ++ret;
		}
	}
	return ret;
}
int main()
{
	int ans=0;
	while (scanf("%s",s)!=EOF){
		ans+=Count();
	}
	printf("%d\n",ans);
	return 0;
}
