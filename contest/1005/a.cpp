/*********************************
Date: Thu Oct  5 13:24:05 CST 2017
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
const int maxn = 1e3 + 100;
vector<int>V[maxn];
int a[maxn];
bool vs[maxn];
int ans=1;
int cnt;
void dfs(int pos,int col)
{
	int t=a[pos];
	if (a[pos]!=-1){
		if (a[pos]!=col){
			ans=0;
			return ;
		}
	}
	else{
		a[pos]=col;
		++cnt;
	}
	vs[pos]=true;
	for (int i=0;i<V[pos].size();++i){
		if (!vs[V[pos][i]]) 
			dfs(V[pos][i],col^1);
		else{
			if (a[V[pos][i]]==a[pos]){
				ans=0;
				a[pos]=t;
				return ;
			}
		}
	}
	a[pos]=t;
}
int main()
{
	int n,m,x,y;
	while (scanf("%d%d%d%d",&n,&m,&x,&y) != EOF){
		int ta,tb;
		Cl(a,-1);
		for (int i=1;i<=1000;++i)
			V[i].clear();
		for (int i=0;i<m;++i){
			scanf("%d%d",&ta,&tb);
			V[ta].push_back(tb);
			V[tb].push_back(ta);
		}
		int t;
		for (int i=0;i<x;++i){
			scanf("%d",&t);
			a[t]=1;
		}
		for (int i=0;i<y;++i){
			scanf("%d",&t);
			a[t]=0;
		}
		ans=1;
		CL(vs);
		cnt=0;
		dfs(1,0);
		if (ans && cnt+x+y==n){
			cout<<"YES"<<endl;
		}
		else{
			ans=1;
			CL(vs);
			cnt=0;
			dfs(1,1);
			if (ans&& cnt+x+y==n){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
