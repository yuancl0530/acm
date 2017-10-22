/*********************************
Date: Fri Sep 15 19:20:51 CST 2017
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
char tmp[maxn];
int main()
{
	while (scanf("%s",s)!=EOF){
		int m;
		scanf("%d",&m);
		int l,r,k;
		while (m--){
			scanf("%d%d%d",&l,&r,&k);
			--l;
			int tt=k%(r-l);
			if (!tt) k=r-l;
			else k=tt;
			int mm=r-l;
			for (int i=l,p=0;i<r;++i,++p){
				int pos=l+(p-tt+mm)%mm;
				tmp[p]=s[pos];
			}
			for (int i=l,p=0;i<r;++i,++p)
				s[i]=tmp[p];
		}
		printf("%s\n",s);
	}
	return 0;
}
