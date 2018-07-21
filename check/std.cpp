/*********************************
Date: Fri Jul 13 13:21:00 CST 2018
Author: ycl
*********************************/
#include <stdio.h>
#include <queue>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
bool vs[maxn];
struct Node
{
	int x,t;
	Node (int x=0,int t=0):x(x),t(t){}
};
bool check(int u)
{
	return !(u < 0 || u >= maxn || vs[u]);
}
int bfs(int s,int k)
{
	vs[s] = true;
	queue<Node> Q;
	Q.push(Node(s));
	vs[s] = true;
	while (!Q.empty()){
		int x = Q.front().x;
		int t = Q.front().t;
		Q.pop();
		if (x == k) return t;
		int u = x + 1;
		if (check(u)) {
			Q.push(Node(u,t+1));
			vs[u] = true;
		}
		u = x - 1;
		if (check(u)) {
			Q.push(Node(u,t+1));
			vs[u] = true;
		}
		u = x*2;
		if (check(u)) {
			Q.push(Node(u,t+1));
			vs[u] = true;
		}
	}
	return -1;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",bfs(n,k));
	return 0;
}
