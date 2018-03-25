/*********************************
Date: Sun Mar 25 16:05:03 CST 2018
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
char s[maxn];
int a[maxn],b[maxn],lch[maxn],rch[maxn],n;
int ans,min_sum;
void init() {ans=INF;min_sum=INF;CL(lch);CL(rch);}
void read(char *s,int *a)
{
	istringstream ss(s);
	n=0;
	int t;
	while (ss>>t){
		a[++n]=t;
	}
}
int build(int l1,int r1,int l2,int r2)
{
	if (l1>r1) return 0;
	int root=b[r2];
	int t=l1;
	int cnt=0;
	while (a[t]!=root){++t; ++cnt;}
	lch[root]=build(l1,l1+cnt-1,l2,l2+cnt-1);
	rch[root]=build(l1+cnt+1,r1,l2+cnt,r2-1);
	return root;
}
void dfs(int u,int s=0)
{
	s+=u;
	if (!lch[u]&&!rch[u]){
		if (s<min_sum){
			min_sum=s;
			ans=u;
		}
		else if (s==min_sum && u<ans){
			ans=u;
		}
		return ;
	}
	if (lch[u]) dfs(lch[u],s);
	if (rch[u]) dfs(rch[u],s);
}
int main()
{
	while (cin.getline(s,maxn)){
		read(s,a);
		cin.getline(s,maxn);
		read(s,b);
		init();
		build(1,n,1,n);
		dfs(b[n]);
		printf("%d\n",ans);
	}
	return 0;
}
