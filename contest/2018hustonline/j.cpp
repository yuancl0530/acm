/*********************************
Date: Sun Apr 29 09:14:29 CST 2018
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
	int i;
	int dis;
	Node(int a=0,int b=1):i(a),dis(b){}
	friend bool operator <(Node a,Node b)
	{
		return a.dis > b.dis;
	}
};
int dis[maxn];
inline int f(int v)
{
	int ret = 0;
	while (v){
		if (v&1){
			++ret;
		}
		v >>=1;
	}
	return ret;
}
void init()
{
	Cl(dis,0x7f);

}
priority_queue<Node>Q;
int a,b;
void dijkstar(int s)
{
	dis[s]=0;
	Q.push(Node(s,0));
	while (!Q.empty()){
		int u = Q.top().i;
		int d = Q.top().dis;
		//cout<<u<<endl;
		Q.pop();
		int v;
		int t=f(u);
		if (u>1e6+20) continue;
		v = u+1;
		if (dis[v]>d+1){
			dis[v]=d+1;
			Q.push(Node(v,d+1));
		}

		v  = u+t;
		if (dis[v]>d+1){
			dis[v]=d+1;
			Q.push(Node(v,d+1));
		}

		if (u==0) continue;
		v = u-1;
		if (dis[v]>d+1){
			dis[v]=d+1;
			Q.push(Node(v,d+1));
		}

		if (u<t)continue;
		v=u-t;
		if (dis[v]>d+1){
			dis[v]=d+1;
			Q.push(Node(v,d+1));
		}

	}
}
int main()
{
	init();
	scanf("%d%d",&a,&b);
	dijkstar(a);
	printf("%d\n",dis[b]);
	return 0;
}
