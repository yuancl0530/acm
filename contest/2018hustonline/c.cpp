/*********************************
Date: Sun Apr 29 10:44:19 CST 2018
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
set<int> S[maxn];
int belong[maxn];
inline void init(int n)
{
	for (int i=1;i<maxn;++i){
		S[i].clear();
		if (i<=n)S[i].insert(i);
		belong[i]=i;
	}
}
int main()
{
	int T;
	int kase = 0;
	scanf("%d",&T);
	while (T--){
		printf("Case #%d:\n",++kase);
		int n,q;
		scanf("%d%d",&n,&q);
		init(n);
		int id = n;
		int op,u,v;
		while (q--){
			scanf("%d%d",&op,&u);
			if (op==1){
				scanf("%d",&v);
				u = belong[u];
				v = belong[v];
				if (u==v) continue;
				set<int>::iterator it;
				if (S[u].size()>=S[v].size()){
					it = S[v].begin();
					for (;it!=S[v].end();++it){
						S[u].insert(*it);
						belong[*it] = u;
					}
					S[v].clear();
				}
				else{
					it = S[u].begin();
					for (;it!=S[u].end();++it){
						S[v].insert(*it);
						belong[*it] = v;
					}
					S[u].clear();
				}
			}
			else if (op==2){
				int t = belong[u];
				S[t].erase(u);
				S[++id].insert(u);
				belong[u] = id;
			}
			else if (op==3){
				printf("%d\n",(int)S[belong[u]].size());
			}
			else{
				scanf("%d",&v);
				printf("%s\n",belong[u]==belong[v]? "YES":"NO");
			}
		}

	}
	return 0;
}
