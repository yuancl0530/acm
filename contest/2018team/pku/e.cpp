/*********************************
Date: Fri Sep  7 16:36:22 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int t;
	int c;
	Node (int t=0,int c=0):t(t),c(c) {}
	friend bool operator < (Node a,Node b)
	{
		if (a.t != b.t) return a.t > b.t;
		return a.c > b.c;
	}
};
int c[110];
int main()
{
	int n,m,q;
	while (scanf("%d%d%d",&m,&n,&q) != EOF){
		priority_queue<Node> Q;
		for (int i = 1;i <= n;++i){
			scanf("%d",c+i);
			Q.push(Node(1,c[i]));
		}
		int b = 0;
		while (m > 0 && Q.top().t <= q){
			int t = Q.top().t;
			int w = Q.top().c;
			Q.pop();
			Q.push(Node(t+w,w));
			--m;
			if (w>1) ++b;
			if (w>1&&t!=1) --b;
		}
		while (!Q.empty()){
			if (Q.top().t != 1 && Q.top().t <= q && Q.top().c>1) --b;
			Q.pop();
		}
		printf("%d %d\n",m,b);
		
	}
	return 0;
}
