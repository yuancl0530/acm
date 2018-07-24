/*********************************
Date: Fri Mar  9 13:03:20 CST 2018
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
struct Node
{
	int x,y,t;
	friend bool operator <(Node a,Node b)
	{
		return a.t<b.t;
	}
}node[maxn];
bool check(int v,int u)
{
	int d=abs(node[v].x-node[u].x) + abs(node[u].y-node[v].y) ;
	int t = node[u].t-node[v].t ;
	if (d<=t && (t-d)%2==0)
		return true;
	else
		return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d%d",&node[i].t,&node[i].x,&node[i].y);
	}
	sort(node,node+n);
	bool f=1;
	for (int i=0;i<n;++i){
		if (!check(i,i+1)){
			f=0;
			break;
		}
	}
	if (f)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
