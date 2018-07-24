/*********************************
Date: Sat May  5 16:56:57 CST 2018
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int x[maxn],y[maxn],p[maxn];
struct Node
{
	int x;
	int v;
	Node(int x=0,int v=0):x(x),v(v){}
	friend bool operator < (Node a,Node b)
	{
		return a.x < b.x;
	}
};
vector<Node>G[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	n+=2;
	int cnt = 0;
	for (int i=0;i<n;++i){
		scanf("%d%d",&x[i],&y[i]);
		p[cnt++] = x[i];
		p[cnt++] = y[i];
	}
	sort(p,p+n);
	for (int i=0;i<n;++i){
		x[i] = lower_bound(p,p+n,x[i]) - p;
		y[i] = lower_bound(p,p+n,y[i]) - p;
		G[y[i]].push_back(Node(x[i]));
	}
	for (int i=0;i<maxn;++i){
		G[i].push_back(Node(-1,0));
		sort(G[i].begin(),G[i].end());
	}
	if (x[0]>x[1]){
		swap(x[0],x[1]);
		swap(y[0],y[1]);
	}
	if (y[0]<y[1]){
		int u = lower_bound(G[y[0]].begin(),G[y[0]].end(),x[0])-G[y[0]].begin();
		for (int i=u;i<G[y[0]].size();++i){
			G[y[0]][i].v = G[y[0]][i-1].v+1;
		}
		for (int i=y[0]+1;i<maxn;++i){
			int s = lower_bound(G[y[0]].begin(),G[y[0]].end(),u)-G[y[0]].begin();
			for (int j=s;j<G[i].size();++i){
				G[i][j].v = G[i][j-1].v + 1;
				int m = lower_bound()
				G[i][j].v = max(G[i][j].v,m)
			}
		}
	}
	return 0;
}
