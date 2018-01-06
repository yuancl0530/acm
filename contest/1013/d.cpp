/*********************************
Date: Fri Oct 13 20:12:42 CST 2017
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
#define INF 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int f,t,c;
	Node (int f,int t,int c):f(f),t(t),c(c){}
};
vector<Node>V[maxn];
LL costa[maxn];
LL costd[maxn];
int cost[maxn];
LL f1[maxn],f2[maxn];
int main()
{
	int n,m,k;
	CL(costa);
	CL(costd);
	scanf("%d%d%d",&n,&m,&k);
	int start=-1,end=-1;
	for (int i=1;i<=m;++i){
		int d,f,t,c;
		scanf("%d%d%d%d",&d,&f,&t,&c);
		V[d].push_back(Node(f,t,c));
	}
	
	int cnt=0;
	Cl(cost,-1);
	for (int i=1;i<maxn;++i){
		costa[i]=costa[i-1];
		for (int j=0;j<V[i].size();++j){
			if (V[i][j].t==0){
				if (cost[V[i][j].f]==-1){
					++cnt;
					cost[V[i][j].f]=V[i][j].c;
					costa[i]+=cost[V[i][j].f];
					if (cnt==n){
						start=i;
					}
				}
				else if (cost[V[i][j].f]>V[i][j].c){	
					costa[i]+=V[i][j].c-cost[V[i][j].f];
					cost[V[i][j].f]=V[i][j].c;
				}
			}
		}
	}

	Cl(cost,-1);
	cnt=0;
	for (int i=maxn-2;i>0;--i){
		costd[i]=costd[i+1];
		for (int j=0;j<V[i].size();++j){
			if (V[i][j].f==0){
				if (cost[V[i][j].t]==-1){
					++cnt;
					cost[V[i][j].t]=V[i][j].c;
					costd[i]+=cost[V[i][j].t];
					if (cnt==n){
						end=i;
					}
				}
				else if (cost[V[i][j].t]>V[i][j].c){	
					costd[i]+=V[i][j].c-cost[V[i][j].t];
					cost[V[i][j].t]=V[i][j].c;
				}
			}
		}
	}

	f1[start-1]=INF;
	for (int i=start;i<=end;++i)
		f1[i]=min(f1[i-1],costa[i]);
	f2[end+1]=INF;
	for (int i=end;i>=start;--i)
		f2[i]=min(f2[i+1],costd[i]);
	
	LL ans=-1;
	if (start<0 || end<0 || start+1+k>end)
		ans=-1;
	else{
		ans=f1[start]+f2[start+1+k];
		for (int i=start;i+1+k<=end;++i)
			ans=min(ans,f1[i]+f2[i+1+k]);
	}
	printf("%lld\n",ans);
	return 0;
}
