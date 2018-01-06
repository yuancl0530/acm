/*********************************
Date: Sun Oct  8 15:02:03 CST 2017
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
const int maxn = 4e4+10;
int deg[maxn];
map<int,int>E[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		int op;
		for (int i=0;i<maxn;i++)
			E[i].clear();
		CL(deg);
		scanf("%d%d",&n,&m);
		int x,y,z,v;
		for (int i=1;i<n;++i){
			scanf("%d%d%d",&x,&y,&v);
			if (v){
				deg[x]++;
				deg[y]++;
			}
			if (x>y)swap(x,y);
			E[x][y]=v;
		}
		while (m--){
			scanf("%d",&op);
			if (op){
				scanf("%d%d%d",&x,&y,&z);
				if (x>y) swap(x,y);
				if (z==E[x][y]) continue;
				if (E[x][y]){
					deg[x]--;
					deg[y]--;
				}
				else{
					deg[x]++;
					deg[y]++;
				}
				E[x][y]=z;
			}
			else{
				scanf("%d",&x);
				if (deg[x]&1)
					cout<<"Girls win!"<<endl;
				else
					cout<<"Boys win!"<<endl;
			}
		}
	}
	return 0;
}
