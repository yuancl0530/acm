/*********************************
Date: Thu Aug 24 12:59:28 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;

struct Node
{
	LL dis;
	bool onway;
};
struct Edge
{
	int u;
	int v;
	bool used;
}edge[maxn];
vector<int>E;
int father[maxn];
int Find(int x)
{
	if (father[x]==x)return x;
	return father[x]=Find(father[x]);
}
void Kruskal()
{
    for (int i = 0;i < m;i++){
        int n1 = Find(edge[i].u);
        int n2 = Find(edge[i].v);
        if(n1 != n2){
            father[n1] = father[n2];
			E[edge[i].v].push_back(edge[i].u);
			E[edge[i].u].push_back(edge[i].v);
			edge[i].used=0;
        }
    }
    return ;
}
LL maxlen=0;
int cal(int pos=1)
{
	if (pos==n){
		retu
		rn node[pos].onway=1;
	}
	for (int i=0;i<E[pos].size();i++){
		int v=E[pos][i];
		node[pos].onway=cal(v);
		if (E[pos].onway)
				
	}
	return node[pos].onway;
}
int main()
{



	return 0;
}
