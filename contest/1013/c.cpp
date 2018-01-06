/*********************************
Date: Fri Oct 13 19:42:03 CST 2017
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
const int maxn = 3e5 + 100;
struct Node
{
	int id;
	int va;
	Node (int id=0,int va=0):id(id),va(va){}
	friend bool operator <(Node a,Node b){
		if (a.va!=b.va)
			return a.va<b.va;
		return 
			a.id>b.id;
	}
};
priority_queue<Node>Q;
int c[maxn];
int ans[maxn];
int main()
{
	int n,k;
	while (scanf("%d%d",&n,&k) != EOF){
		for (int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for (int i=1;i<=k;++i){
			Q.push(Node(i,c[i]));
		}
		LL cost=0;
		for (int i=k+1;i<=n;++i){
			Q.push(Node (i,c[i]));
			int t=Q.top().id;
			Q.pop();
			ans[t]=i;
			cost+=(LL)c[t]*(i-t);
		}
		int i=n+1;
		while (!Q.empty()){
			int t=Q.top().id;
			Q.pop();
			ans[t]=i;	
			cost+=(LL)c[t]*(i-t);
			++i;
		}
		printf("%lld\n",cost);
		for (int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
