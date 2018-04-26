/*********************************
Date: Thu Apr 26 08:40:14 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int m;
	int s;
}p[100];
int main()
{
	int T;
	scanf("%d",&T);
	string s;
	int hh,mm,x,n,m;
	while (T--){
		CL(p);
		scanf("%d%d",&n,&m);
		while (m--){
			scanf("%d %d:%d",&x,&hh,&mm);
			cin>>s;
			if (p[x-1000].s){
				continue;
			}
			if (s=="AC"){
				p[x-1000].s=1;
				p[x-1000].m+=hh*60+mm;
			}
			else if (s!="CE"){
				p[x-1000].m+=20;
			}
		}
		int cnt=0;
		hh=0;
		mm=0;
		for (int i=1;i<=n;++i){
			if (p[i].s){
				mm+=p[i].m;
				++cnt;
			}
		}
		printf("%d %d\n",cnt,mm);
	}
	return 0;
}
