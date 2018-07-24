/*********************************
Date: Wed Jul  4 00:05:35 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
int deg[maxn];
int n,d,k;
vector<int> G[maxn];
int id;
struct Node
{
	int u;
	int d;
	Node (int u,int d):u(u),d(d) {}
};
int solve()
{
	int ans = 1;
	queue<Node>Q;
	int id = 1;
	for (int i = 1;id<n && i <= k;++i){
		G[1].push_back(++id);
		Q.push(Node(id,1));
	}
	while (!Q.empty() && id < n) {
		int u = Q.front().u;
		int t = Q.front().d+1;
		Q.pop();
		if (2*t <= d || k-1>=n-id && 2*t-1<=d) {
			for (int i = 1;i < k;++i){
				Q.push(Node(++id,t));
				G[u].push_back(id);
				if (id >= n) break;
			}
		}
		else
		 return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&d,&k);
	if (solve()){
		printf("YES\n");
		for (int i = 1;i <= n;++i){
			for (int j = 0;j < G[i].size();++j)
				printf("%d %d\n",i,G[i][j]);
		}
	}
	else
		printf("NO\n");
	return 0;
}
