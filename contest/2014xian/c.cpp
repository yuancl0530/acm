/*********************************
Date: Tue Apr  3 19:49:53 CST 2018
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
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
LL X[maxn],Y[maxn],Z[maxn];
int n,m;
LL c[1010][1010];
LL dis[maxn];
int num[maxn];
struct Node
{
	int u;
	LL dis;
	Node(int u=0,LL dis=0):u(u),dis(dis){}
	friend bool operator < (const Node &a,const Node &b)
	{
		a.dis>b.dis;
	}
};
void dijkstra()
{
	priority_queue<Node>Q;
	while (!Q.empty()) Q.pop();
	for (int i=1;i<n;++i){
		Q.push(Node(i,c[0][i]));
		dis[i]=c[0][i];
	}
	dis[0]=0;
	while (!Q.empty()){
		int u=Q.top().u;
		LL d=Q.top().dis;
		Q.pop();
		for (int i=0;i<n;++i){
			if (i==u) continue;
			if (d+c[u][i]<dis[i]){
				dis[i]=d+c[u][i];
				Q.push(Node(i,dis[i]));
			}	
		}
	}
}
void calc()
{
	for (int i=2;i<=n*n+n;++i){
		X[i]  = (12345+X[i-1]*23456%5837501 + X[i-2] * 34567%5837501 + X[i-1] * X[i-2]%5837501*45678%5837501) % 5837501;
		Y[i]  = (56789+Y[i-1]*67890%9860381 + Y[i-2] * 78901%9860381 + Y[i-1] * Y[i-2]%9860381*89012%9860381) % 9860381; 
	}
	for (int i=0;i<=n*n+n;++i){
		Z[i] = (X[i]*90123 + Y[i] ) % 8475871 + 1 ;
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if (i==j) c[i][j]=0;
			else c[i][j]=Z[i*n+j];
		}
	}
}
int main()
{
	while (scanf("%d%d%lld%lld%lld%lld",&n,&m,&X[0],&X[1],&Y[0],&Y[1])!=EOF){
		CL(dis);
		CL(num);
		calc();
		dijkstra();
		for (int i=1;i<n;++i){
			++num[dis[i]%m];
		}
		int ans;
		#ifdef DEBUG
		cout<<"x"<<endl;
		for (int i=0;i<8;++i)
			cout<<X[i]<<" ";
		cout<<endl;
		cout<<"Y"<<endl;
		for (int i=0;i<8;++i)
			cout<<Y[i]<<" ";
		cout<<endl;
		cout<<"Z"<<endl;
		for (int i=0;i<8;++i)
			cout<<Z[i]<<" ";
		cout<<endl;
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j)
				cout<<c[i][j]<<" ";
			cout<<endl;
		}
		#endif
		for (int i=0;i<m;++i){
			if (num[i]){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
